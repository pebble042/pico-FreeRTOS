/* Library includes. */
#include <stdio.h>
#include "pico/stdlib.h"

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"

void create_task(void);

/*-----------------------------------------------------------*/

/* The task functions. */
void vTask1(void *pvParameters);
void vTask2(void *pvParameters);

/*-----------------------------------------------------------*/

void create_task(void)
{
    /* Create one of the two tasks. */
	xTaskCreate(	vTask1,		/* Pointer to the function that implements the task. */
					"Task 1",	/* Text name for the task.  This is to facilitate debugging only. */
					256,		/* Stack depth - most small microcontrollers will use much less stack than this. */
					NULL,		/* We are not using the task parameter. */
					1,			/* This task will run at priority 1. */
					NULL );		/* We are not using the task handle. */

	/* Create the other task in exactly the same way. */
	xTaskCreate( vTask2, "Task 2", 256, NULL, 1 , NULL );


    vTaskStartScheduler();
    /* Execution will only reach here if there was insufficient heap to
    start the scheduler. */
    for( ;; );

}

/*-----------------------------------------------------------*/

void vTask1( void *pvParameters )
{
    const TickType_t xDelay1000ms = pdMS_TO_TICKS( 1000UL );
	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		// vPrintString( pcTaskName );
        printf("Task 1 | Core : %d \n",get_core_num());

		/* Delay for a period. */
        vTaskDelay(xDelay1000ms);

	}
}

/*-----------------------------------------------------------*/

void vTask2( void *pvParameters )
{
    const TickType_t xDelay1000ms = pdMS_TO_TICKS( 1000UL );

	/* As per most tasks, this task is implemented in an infinite loop. */
	for( ;; )
	{
		/* Print out the name of this task. */
		// vPrintString( pcTaskName );
        printf("Task 2 | Core : %d \n",get_core_num());
		/* Delay for a period. */
        vTaskDelay(xDelay1000ms);
	}
}

/*-----------------------------------------------------------*/


