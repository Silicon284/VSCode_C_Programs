#include <stdio.h>

#pragma warn +xxx (To show the warning)
#pragma warn -xxx (To hide the warning)
#pragma warn .xxx (To toggle between hide and show)

//#pragma GCC poison printf

void __attribute__((constructor)) function_a();  
void __attribute__((destructor)) function_b(); 

void function_a (void) {

    printf("I am Function A \n\r");
}

void function_b (void) {

    printf("I am Function B \n\r");
}

int main(void) {

    printf("I am Function Main \n\r");
    return 0;
}