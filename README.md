# Jupiter_RTOS

Microcontroller OS based off of FreeRTOS.

## setup instructions

### Arduino Due

1. use code derivative: https://github.com/greiman/FreeRTOS-Arduino
2. cp -r FreeRTOS-Arduino/libraries/FreeRTOS_ARM/ ~/Arduino/libraries/
3. start Arduino IDE for compiling and reflash on due board.


## FreeRTOS reference for Arduino Due

### tasks

creating tasks:
===================

1. use `xTaskCreate` to create a task.

prototype:

```c
BaseType_t xTaskCreate(TaskFunction_t taskcode,
					   const char * const name,
					   configSTACK_DEPTH_TYPE stack_size,
					   void *params,
					   UBaseType_t priority,
					   TaskHandle_t *task);
```

example:

```c

// task function
void task1(void *task_data)
{
}

xTaskCreate(task1, "task1", 1000, NULL, tskIDLE_PRIORITY, NULL);


```

parameters:
1. task1 - callback function to be called when this task is created
2. "task1" - name of task
3. 1000 - stack depth
4. NULL - task specific parameter
5. tskIDLE_PRIORITY - default low priority
6. NULL - used to pass out the created task handle


2. more than one task can be created with `xTaskCreate` calling multiple times


creating queues:
===================

1. use `xQueueCreate` to create a queue.


prototype:

```c
QueueHandle_t xQueueCreate(UBaseType_t queuelength, UBaseType_t itemsize);
```

example:


```c
QueueHandle_t queue_h;

// create a queue with 10 int
queue_h = xQueueCreate(10, sizeof(int));
```

2. use `xQueueSend` to send a message and `xQueueReceive` to receive a message.

prototype:

```c

BaseType_t xQueueSend(QueueHandle_t queue, const void *que_var, TickType_t wait_time_ticks);
BaseType_t xQueueReceive(QueueHandle_t queue, void *que_var, TickType_t wait_time_ticks);

```

Queues can be used to send and receive messages between tasks. example:

```c

QueueHandle_t queue_h;

void task1(void *task1_ptr)
{
    int counter = 0;
    while (1) {
	    xQueueSend(queue_h, (void *)&counter, (TickType_t)10);
		vTaskDelay((TickType_t)500);
		counter ++;
	}
}

void task2(void *task2_ptr)
{
    int counter = 0;
	while (1) {
		xQueueReceive(queue_h, (void *)&counter, (TickType_t)10);
		vTaskDelay((TickType_t)500);
	}
}

queue_h = xQueueCreate(10, sizeof(int));
xTaskCreate(task1, "task1", 1000, NULL, tskIDLE_PRIORITY, NULL);
xTaskCreate(task2, "task2", 1000, NULL, tskIDLE_PRIOTITY, NULL);
```

