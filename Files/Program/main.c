#include "stdio.h"

void main() {

  int num1, num2, sum;
  float float1,float2, sum2;
  char str[32];

  // Display the program title
  PRINT("Program: Add Two Numbers\n");

  while (1) {

    PRINT("------------------------------\n");

    // Prompt for the first number
    PRINT("Enter first number: ");
    READ("%d", &num1);

    // Prompt for the second number
    PRINT("Enter second number: ");
    READ("%d", &num2);

    // Calculate the sum
    sum = num1 + num2;

    // Display the result
    PRINT("%d + %d = %d \n", num1, num2, sum);

    // Prompt for the first number
    PRINT("Enter first float number: ");
    READ("%f", &float1);

    // Prompt for the second number
    PRINT("Enter second float number: ");
    READ("%f", &float2);

    // Calculate the sum
    sum2 = float1 + float2;

    // Display the result
    PRINT("%f + %f = %f \n", float1, float2, sum2);
  }
}
/*
void main() {
    char input1[16];
    char input2[16];
    char result_str[16];
    int num1, num2, sum;

    uart_puts("Program: Add Two Numbers\n");

    while (1) {
        // Prompt for first number
        uart_puts("Enter first number: ");
        uart_gets_input(input1, sizeof(input1));
        num1 = uart_atoi(input1);

        // Prompt for second number
        uart_puts("Enter second number: ");
        uart_gets_input(input2, sizeof(input2));
        num2 = uart_atoi(input2);

        // Calculate sum
        sum = num1 + num2;

        // Convert sum to string
        uart_itoa(sum, result_str);

        // Display the result
        uart_puts("Sum: ");
        uart_puts(result_str);
        uart_putc('\n');
    }
}
*/
