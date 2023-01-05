#ifndef SPACEBUTTON_CONFIG

#define WIFI_SSID "osaa-iot"
#define WIFI_PASS "deadbeef42"
#define ENDPOINT_SET_URL "http://spaceapi.osaa.dk/sensor/set"
#define ENDPOINT_GET_URL "http://spaceapi.osaa.dk/status/json"
/* Calculated by using http://arduinojson.org/assistant/ on http://spaceapi.osaa.dk/status/json */
#define MAX_JSON_RESPONSE_SIZE 2048
#define PULL_WAIT_MS 2000
#define BUTTON_POLL_MS 10
#define DEBOUNCE_COUNT 8
#define POST_CHANGE_REQ_DELAY_MS 2000

#define PAYLOAD_OPEN    "sensors=%7B%22state%22%3A%7B%22open%22%3Atrue%7D%7D&key=qCUlkiJTqzI3ClxguW2v.etqpOUwi85djis7p.Vicg3a8vjPfCcEG"
#define PAYLOAD_CLOSE   "sensors=%7B%22state%22%3A%7B%22open%22%3Afalse%7D%7D&key=qCUlkiJTqzI3ClxguW2v.etqpOUwi85djis7p.Vicg3a8vjPfCcEG"

#define RED_PIN     13
#define YELLOW_PIN  12
#define GREEN_PIN   14
#define BUTTON_PIN  15
//#define RED_PIN     D7
//#define YELLOW_PIN  D6
//#define GREEN_PIN   D5
//#define BUTTON_PIN  D8
#define PIN_ON      1
#define PIN_OFF     0

#define NUMBER_OF_TRIES_BEFORE_RESET 60
#define FLASH_LEDS_N_TIMES_BEFORE_RESET 5
#define FLASH_LEDS_INTERVAL_IN_MS 700

#endif
