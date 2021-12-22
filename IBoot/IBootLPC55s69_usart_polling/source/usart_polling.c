/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pin_mux.h"
#include "board.h"
#include "fsl_usart.h"
#include <stdbool.h>
#include "fsl_power.h"
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define DEMO_USART          USART0
#define DEMO_USART_CLK_SRC  kCLOCK_Flexcomm0
#define DEMO_USART_CLK_FREQ CLOCK_GetFlexCommClkFreq(0U)

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/

uint8_t u8InterruptBoot = 0U;

/*******************************************************************************
 * Code
 ******************************************************************************/
/*!
 * @brief Main function
 */
int main(void)
{
    uint8_t ch;
    usart_config_t config;
    uint8_t *txData;

    /* set BOD VBAT level to 1.65V */
    POWER_SetBodVbatLevel(kPOWER_BodVbatLevel1650mv, kPOWER_BodHystLevel50mv, false);
    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);

    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitDebugConsole();
    /*
     * config.baudRate_Bps = 115200U;
     * config.parityMode = kUSART_ParityDisabled;
     * config.stopBitCount = kUSART_OneStopBit;
     * config.loopback = false;
     * config.enableTx = false;
     * config.enableRx = false;
     */
    USART_GetDefaultConfig(&config);
    config.baudRate_Bps = BOARD_DEBUG_UART_BAUDRATE;
    config.enableTx     = true;
    config.enableRx     = true;

    USART_Init(DEMO_USART, &config, DEMO_USART_CLK_FREQ);


#if 0
    while (1)
    {
        USART_ReadBlocking(DEMO_USART, &ch, 1);
        USART_WriteBlocking(DEMO_USART, &ch, 1);
    }

#endif

    /* Lets check whether button is pressed or not, if not pressed jump to user application */
    if (1U == u8InterruptBoot)
    {

    	txData = "Interrupting normal booting process\n";
        USART_WriteBlocking(DEMO_USART, txData, sizeof(txData) - 1);


  	  //we should continue in bootloader mode
  	  //IBoot_uart_read_data();

    }
    else
    {
    	txData = "Jumping to user application\n";
        USART_WriteBlocking(DEMO_USART, txData, sizeof(txData) - 1);

  		//jump to user application
  		//IBoot_jump_to_user_app();

    }

    while(1);

}
