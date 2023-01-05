#include <ESP8266HTTPClient.h>
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
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
int resetCounter = 0;

void setup() {

  pinMode(GREEN_PIN, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT); 
  setAllPins(true);

  Serial.begin(9600);
  while (!Serial) continue;

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(WIFI_SSID, WIFI_PASS);

  // allow reuse (if server supports it)
  http.setReuse(true); 
  setAllPins(false);
}

void setPin(pinout_t pin, bool output) {
  //Serial.print("pin ");
  //Serial.print(pin);
  //Serial.print(" state ");
  //Serial.println(output);
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

void flashLedsAndReset() {
  Serial.println("Resetting due to lack of connectivity");
  bool ledsOn = false;
  for (int counter = 0; counter < 2 * FLASH_LEDS_N_TIMES_BEFORE_RESET; counter++) {
    setAllPins(ledsOn = !ledsOn);
    delay(FLASH_LEDS_INTERVAL_IN_MS);
  }
  // Note: First restart after flash will fail. See:
  // https://github.com/esp8266/Arduino/issues/1722
  ESP.restart();
}

void handleNotConnected() {
  if (++resetCounter >= NUMBER_OF_TRIES_BEFORE_RESET) {
    flashLedsAndReset();
  } else {
      Serial.print("Reset counter is now ");
      Serial.println(resetCounter);
  }
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
    http.useHTTP10(true);
    http.begin(ENDPOINT_GET_URL);
    Serial.println("Trying to fetch status");
    int httpStatus = http.GET();
    if(httpStatus > 0) {
      Serial.print("Got response with HTTP status ");
      Serial.println(httpStatus);
      if(httpStatus == HTTP_CODE_OK) {
        StaticJsonBuffer<MAX_JSON_RESPONSE_SIZE> jsonBuffer;
        //Serial.println("raw JSON was:");
        JsonObject& root = jsonBuffer.parseObject(http.getStream());
        //root.prettyPrintTo(Serial);
        bool state_open = root["state"]["open"].as<bool>();
        result = (state_open ? STATUS_OPEN : STATUS_CLOSED);
        Serial.print("Space state is now: ");
        Serial.println(state_open ? "Open " : "Closed ");
        //Serial.print("Max response buffer size: ");
        //Serial.print(MAX_JSON_RESPONSE_SIZE);        
        setPin(GREEN_PIN, state_open);
        setPin(RED_PIN, !state_open);
      } 
    }
    http.end();
    setPin(YELLOW_PIN, false);
    return result;
  } else {
    handleNotConnected();
  }
}

void buttonPushed() {
  Serial.println("Button pushed");

  toggleOpenStatus();
}

void loop() {
  if ((pullStatusCounter++ % (PULL_WAIT_MS / BUTTON_POLL_MS)) == 0) {
    Serial.println("space status fetch triggered");
    lastKnownStatus = getSpaceStatus();
  }
  int currentRead = digitalRead(BUTTON_PIN);
  accumulated += (currentRead > 0 ? 1 : -1);
//  accumulated += (currentRead > 0 ? -1 : 1);
  accumulated = (accumulated < 0 ? 0 : accumulated);
  if (accumulated >= DEBOUNCE_COUNT) {
    buttonPushed();
    accumulated = 0;
  }
  delay(BUTTON_POLL_MS);
}
