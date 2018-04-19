#ifndef DEBUG_ARDUINO_H

#define SERIAL_BAUD_RATE 9600

void init_debug() {
#ifdef DEBUG_OUT
  Serial.begin(SERIAL_BAUD_RATE);
  while (!Serial) continue;
#else
  return;
#endif /* DEBUG_OUT */  
}

void debug(const char * output) {
#ifdef DEBUG_OUT
  Serial.print(output);
#else
  return;
#endif /* DEBUG_OUT */
}

void debugln(const char * output) {
#ifdef DEBUG_OUT
  Serial.println(output);
#else
  return;
#endif /* DEBUG_OUT */
}

void debug(int output) {
#ifdef DEBUG_OUT
  Serial.print(output);
#else
  return;
#endif /* DEBUG_OUT */
}

void debugln(int output) {
#ifdef DEBUG_OUT
  Serial.println(output);
#else
  return;
#endif /* DEBUG_OUT */
}

#endif /* DEBUG_ARDUINO_H */
