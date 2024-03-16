#include <stdio.h>

void function_a (int a);
void function_b (int x);
void init_sensors(void);

int q = 4;

struct sensor {
int iD;
char warn_msg[20];
void (*fun_read)(int);
int *data_ptr;
};

struct sensor ECG, spo;
struct sensor *sense;

int main(void) {

    int var_1 = 10;
    printf ("Printing Variable = %d \n\r", var_1);
    init_sensors();
    sense = &ECG;
    printf ("Result : %d \n\r", sense->iD);

    return 0;
}

void init_sensors(void) {
    
    char ECG_char[20] = "I am ECG";
    int i = 0, j = 0;

    ECG.iD = 0xAA;
    while (ECG_char[i] != '\0') {
        ECG.warn_msg[i] = ECG_char[i];
        i++;
    }
    ECG.fun_read = (void(*)(int))(function_a);
    ECG.data_ptr = (int*)0x20202020;

    char spo_char[20] = "Check Finger";

    spo.iD = 0xCC;
    while (spo_char[j] != '\0') {
        spo.warn_msg[j] = spo_char[j];
        j++;
    }
    spo.fun_read = (void(*)(int))function_b;
    spo.data_ptr = (int*) 0x12121212;
}
void function_a (int a) {
    printf("Hello_World from function A with input number : %d \n\r", a);
}

void function_b (int x) {
    printf("Hello World from function B with input number : %d \n\r", x);
}
