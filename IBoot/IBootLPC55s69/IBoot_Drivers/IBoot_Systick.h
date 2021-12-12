/* Systick driver APIs used in IBoot */

#include "core_cm33.h"

void SysTick_Handler(void);

uint32_t SysTick_Init(uint32_t ticks, uint8_t bEnSysTick, uint8_t bEnSysTickInt);

