#include <stdint.h>

void LedsCreate(uint16_t *address);
void LedsSingleTurnOn(uint8_t led);
void LedsSingleTurnOff(uint8_t led);
void LedsTurnOn(void);
void LedsTurnOff(void);
uint8_t LedsGetLedState(uint8_t led);