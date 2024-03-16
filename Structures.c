#include <stdio.h>


 #define NUMBER_OF_TESTS 3

int function_a (void);
int function_b (void);
int function_c (void);

struct g_st_test_template {

    int (*function_ptr[NUMBER_OF_TESTS])(void);
    int status;
    char *result;
    int result_array[NUMBER_OF_TESTS];
};

int l_status                                =   10;
char l_string_result[NUMBER_OF_TESTS]       =   "A";
int l_result_final                          =   11;
int (*function_list[NUMBER_OF_TESTS])(void) =   {function_a, function_b, function_c};

struct g_st_test_template g_st_test_struct;

void fn_launch_test(struct g_st_test_template *g_st_test_firmware) {

    int l_test = 0;
    int l_count = 0;
    *(g_st_test_firmware->result) = 'F';

    for (int i = 0; i < NUMBER_OF_TESTS; i++) {
        g_st_test_firmware->result_array[i] = (g_st_test_firmware->function_ptr[i])();
        if (g_st_test_firmware->result_array[i] != 0)
            g_st_test_firmware->status = 1;
        else 
            g_st_test_firmware->status = 0;
    }

    while ( (g_st_test_firmware->status != 0) && (l_count < NUMBER_OF_TESTS) ) {
        *(g_st_test_firmware->result) = 'P';
        l_count++;
    }
}

int main(void) {
        
    g_st_test_struct.function_ptr[0]        =   function_list[0];
    g_st_test_struct.function_ptr[1]        =   function_list[1];
    g_st_test_struct.function_ptr[2]        =   function_list[2];
    g_st_test_struct.status                 =   l_status;
    g_st_test_struct.result                 =   l_string_result;
    g_st_test_struct.result_array[0]        =   l_result_final;

    printf ("Printing Variable 1 = %x \n\r", (g_st_test_struct.function_ptr[0]));
    printf ("Printing Variable 2 = %x \n\r", function_list[0]);
    printf ("Printing Variable 3 = %c \n\r", g_st_test_struct.result[0]);
    printf ("Printing Variable 4 = %d \n\r", g_st_test_struct.result_array[0]);
    printf ("Printing Variable 5 = %d \n\r", g_st_test_struct.status);
    
    fn_launch_test (&g_st_test_struct);

    printf ("Printing Variable 1 = %x \n\r", (g_st_test_struct.function_ptr[0]));
    printf ("Printing Variable 2 = %x \n\r", function_list[0]);
    printf ("Printing Variable 3 = %c \n\r", g_st_test_struct.result[0]);
    printf ("Printing Variable 4 = %d \n\r", g_st_test_struct.result_array[0]);
    printf ("Printing Variable 5 = %d \n\r", g_st_test_struct.status);
    
    printf ("Test Completed \n\r");

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