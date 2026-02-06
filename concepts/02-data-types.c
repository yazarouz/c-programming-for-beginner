// data_types_demo.c
// A practical demonstration of basic data types in C
//auther: yazarouz      date: 2025/11/22 
#include <stdio.h>
int main() {
    //Integer (whole number)
    int myInt = 100;

    //Float (single_precision decimal number)
    float myFloat = 3.14f;

    //Double (double_precision decimal number)
    double myDouble = 2.98765432;

    //Character (single letter or symbol)
    char myChar = 'A';

    //Unsinged integer (non_negative only)
    unsigned int myUnsinged = 87654356;

    //Long long (very large integer (typically 64-bit))
    long long mybignumber = 876543467896565LL;

    //Print all value
    printf("=== C Data Types Demonstration ===\n\n");

    printf("int             : %d\n" , myInt);
    printf("float           : %f\n" , myFloat);
    printf("double          : %f\n" , myDouble);
    printf("character       : %c\n" , myChar);
    printf("unsinged int    : %u\n" , myUnsinged);
    printf("long long       :%lld\n" , mybignumber);

    printf("\n Tip: Each data type uses different memory:\n");
    printf("Size of int     : %zu bytes\n", sizeof(int));
    printf("Size of float   : %zu bytes\n", sizeof(float));
    printf("Size of double  : %zu bytes\n", sizeof(double));
    printf("Size of char    : %zu bytes\n", sizeof(char));

    return 0;
}