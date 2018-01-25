#ifndef SPACEBUTTON_H

#define STATUS_CLOSED     0
#define STATUS_OPEN       1
#define STATUS_UNDEFINED  -1

typedef int pinout_t;
typedef int space_status_t;

bool readPin(pinout_t pin);
void setPin(pinout_t pin, bool output);
void setPins(bool green, bool red, bool yellow);
void setAllPins(bool all);
void setOpenStatus(space_status_t spaceStatus);
void togglePin(pinout_t pin);

#endif
