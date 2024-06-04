/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"
#include "uart.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void vAperiodicUART(void *pmParam)
{
	while(1)
	{
		UartPuts("HELLO!\r\n");
		UartPuts("THIS IS MUSKAN!\r\n");
		vTaskDelay(1000/portTICK_RATE_MS);

	}
	vTaskDelete(NULL);
}

int main()
{
	UartInit(BAUD_9600);
	xTaskCreate(vAperiodicUART,"UART",configMINIMAL_STACK_SIZE,NULL,2,NULL);

	vTaskStartScheduler();


	return 0;
}




