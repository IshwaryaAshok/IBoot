/* Systick driver APIs used in IBoot */

#include "IBoot_Systick.h"

void SysTick_Handler(void)
{
	while(1);
}


/**
  \brief   System Tick Configuration
  \details Initializes the System Timer and its interrupt, and starts the System Tick Timer.
           Counter is in free running mode to generate periodic interrupts.
  \param [in]  ticks  Number of ticks between two interrupts.
  \return          0  Function succeeded.
  \return          1  Function failed.
  \note    When the variable <b>__Vendor_SysTickConfig</b> is set to 1, then the
           function <b>SysTick_Config</b> is not included. In this case, the file <b><i>device</i>.h</b>
           must contain a vendor-specific implementation of this function.
 */
uint32_t SysTick_Init(uint32_t ticks, uint8_t bEnSysTick, uint8_t bEnSysTickInt)
{
  if ((ticks - 1UL) > SysTick_LOAD_RELOAD_Msk)
  {
    return (1UL);                                                   /* Reload value impossible */
  }

  SysTick->LOAD  = (uint32_t)(ticks - 1UL);                         /* set reload register */
  NVIC_SetPriority (SysTick_IRQn, (1UL << __NVIC_PRIO_BITS) - 1UL); /* set Priority for Systick Interrupt */
  SysTick->VAL   = 0UL;                                             /* Load the SysTick Counter Value */

  /* Select Processor clock as Systick timer clock source */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk ;

  if(1U == bEnSysTickInt)
  {
	  /* Enable SysTick IRQ */
	  SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
  }

  if(1U == bEnSysTick)
  {
	  /* Enable SysTick timer */
	  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  }

  return (0UL);
}
