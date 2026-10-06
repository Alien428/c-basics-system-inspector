#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <uchar.h>

/* **** Helper Functions **** */
void verdoppeln(float *ptr) {
    *ptr = *ptr * 2.0f;
}

/* Devenition main Daty type */
struct systemStatus {
    int sensor_id;
    float voltage;
    int temp_celsius;
    char status;
};

int main(void){

/* **** Part 1: Data Types **** */

printf("Size: %zu Byte\n", sizeof(char));

printf("Size: %zu Byte\n", sizeof(int));

printf("Size: %zu Byte\n", sizeof(float));

printf("Size: %zu Byte\n", sizeof(double));

printf("Size: %zu Byte\n", sizeof(uint8_t));

printf("Size: %zu Byte\n", sizeof(uint64_t));

printf("Size: %zu Byte\n", sizeof(void*));


/* **** Part 2: Voltage Measurement **** */

float voltage = 0.0f;

printf("\n---- Part 2: Voltage Measurement ----\n");
printf("Enter the measured voltage (e.g. 12.5): ");

int result = scanf("%f", &voltage);

if (result == 1){
    printf("Successfully read voltage: %.2f V\n", voltage);
} else {
    printf("Error: Invalid input! Expected a number.\n");
}


/* **** Part 3: Pass-by-Reference **** */
 
printf("\n---- Part 3: Pass-by-Reference ----\n");

float *ptr = &voltage;

printf("Address: %p\n", (void*)ptr);

printf("Value: %.2f\n", *ptr);

*ptr = 28.0f;

printf("New voltage directly: %.2f\n", voltage); 

verdoppeln(&voltage);

printf("Voltage after doubling via function: %.2f\n", voltage);


/* **** Arrays & Pointer-Arithmetik **** */

float voltages[5] = {12.1f, 12.3f, 12.5f, 12.0f, 11.9f};

printf ("First value via index: %.1f V\n", voltages[0]);

printf("First value via pointer: %.1f V\n", *voltages);

printf("Second value via pointer: %.1f V\n", *(voltages + 1));
printf("Third value via pointer:  %.1f V\n", *(voltages + 2));

for (int i = 0; i < 5; i++) {
    printf("Measurement %d: %.1f V (Address: %p)\n", i + 1, *(voltages + i), (void*)(voltages + i));
}
printf("\n Part 5: Structs (Custom Data Types) ---\n");

struct systemStatus main_sensor = {
    .sensor_id = 101,
    .voltage = 12.3f,
    .temp_celsius = 45,
    .status = 'A'
};

printf("Sensor ID: %d\n", main_sensor.sensor_id);
printf("Voltage: %.1f V\n", main_sensor.voltage);
printf("Temperature: %d C\n", main_sensor.temp_celsius);
printf("Starus: %c\n", main_sensor.status);

printf("Size of struct: %lu Bytes\n", sizeof(struct systemStatus));

return 0;

}