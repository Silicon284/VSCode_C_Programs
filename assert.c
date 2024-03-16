#include <stdio.h>
#include <assert.h>

void function_a (int a) {

    assert (a > 5);
    printf("I am Function A \n\r");
}

int main(void) {

    function_a(7);
    
    printf("Calling assert failure parameter \n\r");

    return 0;
}