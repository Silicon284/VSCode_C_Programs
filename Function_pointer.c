
#include <stdio.h>

int function_a (void) {
    printf("I am function A \n\r");
    return 5;
}

int function_b (void) {
    printf ("I am function B \n\r");
    return 2;
}

int (*function_ptr[3])(void) = { function_a, function_b };

int main (void) {
    
    printf("%d \n\r", (function_ptr[0])());
    printf("%d \n\r", function_ptr[1]());
    printf("%d \n\r", function_ptr[0]);
    printf("Function_Name = %d \n\r", function_a);
    printf("Function_Call = %d \n\r", function_a());
    printf("%d \n\r", sizeof(function_ptr));
    printf("%d \n\r", sizeof(function_a));

    return 3;
}