#include "FreeRTOS_ARM.h"
/* Demo includes. */
#include "basic_io_arm.h"

void task1(void *param)
{
  while (1) {
    vPrintString("task1\r\n");
    vTaskDelay(100);
  }
}

void setup( void )
{
  Serial.begin(9600);
  xTaskCreate(task1, "task1", 1000, NULL, tskIDLE_PRIORITY, NULL);
  vTaskStartScheduler();
}
/*-----------------------------------------------------------*/


void loop() {}
