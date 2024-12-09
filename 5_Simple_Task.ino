#include <Arduino_FreeRTOS.h>

// Task handles
TaskHandle_t Task1Handle;
TaskHandle_t Task2Handle;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(9600);

  // Create Task1: This task prints "Task 1 is running"
  xTaskCreate(Task1, "Task 1", 128, NULL, 1, &Task1Handle);

  // Create Task2: This task prints "Task 2 is running"
  xTaskCreate(Task2, "Task 2", 128, NULL, 1, &Task2Handle);
}

void loop() {
  // The loop() function is now idle, as tasks are being handled by FreeRTOS
}

void Task1(void *pvParameters) {
  while (1) {
    Serial.println("Task 1 is running");
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
  }
}

void Task2(void *pvParameters) {
  while (1) {
    Serial.println("Task 2 is running");
    vTaskDelay(pdMS_TO_TICKS(500));  // Delay for 0.5 seconds
  }
}
