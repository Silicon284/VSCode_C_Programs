
/*
On dereferencing a pointer expression we get a value pointed to by that pointer expression. 
Pointer to an array points to an array, so on dereferencing it, we should get the array, 
and the name of array denotes the base address. So, whenever a pointer to an array is dereferenced, 
we get the base address of the array to which it points. 
*/

#include <stdio.h>

int arr_1D[4]       = { 1, 2, 3, 4 };
int arr_2D_c[4][4]  = { {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 16} };
int arr_2D_d[4][4]  = { {1, 5, 9, 13}, {2, 6, 10, 14}, {3, 7, 11, 15}, {4, 8, 12, 16} };
int arr_2D_a[3][3]  = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };
int arr_2D_b[3][3]  = { {1, 1, 1}, {1, 1, 1}, {1, 1, 1} };

void print_1D_array     (int *p, int arr_len);
void print_2D_array     (int *p, int arr_len);
void add_2D_arrays      (int *a, int *b, int arr_len);
void multiply_2D_arrays (int *a, int *b, int arr_len);

int main (void) {

    print_1D_array (arr_1D, 4);
    print_2D_array ((int *)arr_2D_c, 4);
    add_2D_arrays ((int *)arr_2D_c, (int *)arr_2D_d, 4);
    multiply_2D_arrays ((int *)arr_2D_a, (int *)arr_2D_b, 3);

    return 1;
}

void print_1D_array (int *p, int arr_len) {

    printf("printing 1D array \n\r");
    for (int i = 0; i < arr_len; i++) {
        printf ("%d \t", *p);
        *p++;
    }
    printf("\n\r");
}

void print_2D_array (int *a, int arr_len) {

    int (*arr_a)[arr_len] = (int (*)[arr_len])a;

    printf(" \n\r Printing 2D array \n\r");
    for (int i = 0; i < arr_len; i++) {
        for (int j = 0; j < arr_len; j++) {
            printf("%d \t", (*(*(arr_a + i) + j)));
        }
    printf("\n\r");
    }
}

void add_2D_arrays (int *a, int *b, int arr_len) {

    int (*arr_a)[arr_len] = (int (*)[arr_len])a;
    int (*arr_b)[arr_len] = (int (*)[arr_len])b;
    int res[arr_len][arr_len];
    
    printf("\n\r Addition of 2D array \n\r");
    for (int i = 0; i < arr_len; i++) {
        for (int j = 0; j < arr_len; j++) {
            res[i][j] = ( *(*(arr_a + i) + j) + (*(*(arr_b + i) + j)) );
            printf("%d \t", ( res[i][j] ));
        }
        printf("\n\r");
    }
}

void multiply_2D_arrays (int *a, int *b, int arr_len) {
    
    int (*arr_a)[arr_len] = (int (*)[arr_len])a;
    int (*arr_b)[arr_len] = (int (*)[arr_len])b;
    int res[arr_len][arr_len];

    printf("\n\r Dot Multiplication of 2D arrays \n\r");
    for (int i = 0; i < arr_len; i++) {
        for (int j = 0; j < arr_len; j++) {
            int result = 0;
            for (int k = 0; k < arr_len; k++) {
                result += (*(*(arr_a + i) + k)) * (*(*(arr_b + k) + j));
            }
            printf("%d \t", result);
            res[i][j] = result;
        }
        printf("\n\r");
    }
}