#include <stdio.h>

#define NO_OF_FUNCTION_CALLS 3

int function_a (void);
int function_b (void);
int function_c (void);

int (*function_pointer[NO_OF_FUNCTION_CALLS])(void) = {
    function_a,
    function_b,
    function_c
};

int main (void) {
    
    int function_results [NO_OF_FUNCTION_CALLS] = {0};

    for (int i = 0; i < NO_OF_FUNCTION_CALLS; i++) {
        function_results [i] = (function_pointer[i])();
        printf ("Result[%d] = %d \n\r", i, function_results[i]);
    }

    return 0;
}

int function_a (void) {
    printf ("I am function A \n\r");
    return 1;
}

int function_b (void) {
    printf ("I am function B \n\r");
    return 2;
}

int function_c (void) {
    printf ("I am function C \n\r");
    return 3;
}