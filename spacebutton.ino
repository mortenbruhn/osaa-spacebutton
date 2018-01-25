#include <ESP8266HTTPClient.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "spacebutton.h"
#include "config.h"

ESP8266WiFiMulti WiFiMulti;
HTTPClient http;
HTTPClient httpPost;

space_status_t lastKnownStatus = STATUS_UNDEFINED;
int currentRead;
int accumulated = 0;
int pullStatusCounter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial) continue;

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); 

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(WIFI_SSID, WIFI_PASS);

  // allow reuse (if server supports it)
  http.setReuse(true);  
}

void setPin(pinout_t pin, bool output) {
  digitalWrite(pin, (output ? PIN_ON : PIN_OFF));
}

void setPins(bool green, bool red, bool yellow) {
  setPin(GREEN_PIN, green);
  setPin(RED_PIN, red);
  setPin(YELLOW_PIN, yellow);
}

void setAllPins(bool all) {
  setPins(all,all,all);
}

void sendStatusUpdate(space_status_t st) {
  httpPost.begin(ENDPOINT_SET_URL);
  httpPost.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int httpStatus = httpPost.POST((st == STATUS_OPEN) ? PAYLOAD_OPEN : PAYLOAD_CLOSE);
  httpPost.end();
}

void setOpenStatus(space_status_t spaceStatus) {
  switch (spaceStatus) {
    case STATUS_CLOSED:
      sendStatusUpdate(STATUS_CLOSED);
      setPins(false,true,false);
      break;
    case STATUS_OPEN:
      sendStatusUpdate(STATUS_OPEN);
      setPins(true,false,false);
      break;
    default:
      setPins(true,true,false);
  }
  lastKnownStatus = spaceStatus;
  delay(POST_CHANGE_REQ_DELAY_MS);
}

void toggleOpenStatus() {
  switch (lastKnownStatus) {
    case STATUS_CLOSED:
      setOpenStatus(STATUS_OPEN);
      break;
    case STATUS_OPEN:
      setOpenStatus(STATUS_CLOSED);
      break;
    default:
      Serial.println("unknown last known status");
      break;
  }
}

bool readPin(pinout_t pin) {
  return digitalRead(pin);
}

void togglePin(pinout_t pin) {
  bool pinStatus = readPin(pin);
  setPin(pin, !pinStatus);
}

space_status_t getSpaceStatus() {
  space_status_t result = STATUS_UNDEFINED;
  setPin(YELLOW_PIN, true);
  if((WiFiMulti.run() == WL_CONNECTED)) {
    http.begin(ENDPOINT_GET_URL);
    int httpStatus = http.GET();
    if(httpStatus > 0) {
      Serial.print("Got response with HTTP status ");
      Serial.println(httpStatus);
      if(httpStatus == HTTP_CODE_OK) {
        StaticJsonBuffer<MAX_JSON_RESPONSE_SIZE> jsonBuffer;
        bool state_open = (jsonBuffer.parseObject(http.getStream()))["state"]["open"];
        result = (state_open ? STATUS_OPEN : STATUS_CLOSED);
        setPin(YELLOW_PIN, false);
        setPin(GREEN_PIN, state_open);
        setPin(RED_PIN, !state_open);
      } 
    }
    http.end();
    return result;
  }
}

void buttonPushed() {
  toggleOpenStatus();
}

void loop() {
  if ((pullStatusCounter++ % (PULL_WAIT_MS / BUTTON_POLL_MS)) == 0) {
    Serial.println("space status fetch triggered");
    lastKnownStatus = getSpaceStatus();
  }
  int currentRead = digitalRead(BUTTON_PIN);
  accumulated += (currentRead > 0 ? -1 : 1);
  accumulated = (accumulated < 0 ? 0 : accumulated);
  if (accumulated >= DEBOUNCE_COUNT) {
    buttonPushed();
    accumulated = 0;
  }
  delay(BUTTON_POLL_MS);
}
