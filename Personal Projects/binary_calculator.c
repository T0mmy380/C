#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <unistd.h> // Imports "system("cls||clear")" and "system("pause")" function

void choice(int, int, int, int[], char[]);

void decimalToBinary(int, int[]);
void decimalToHex(int, char[]);

void binaryToDecimal(int, int[]);
void binaryToHex(int, int[], char[]);

void main()
{
    system("cls || clear");

    int base1, base2;

    // The decimal number
    int decimal = 0;

    int arr_length = 0;
    // Binary number
    int binary_num[arr_length];
    char hex_num[arr_length];

    choice(base1, base2, decimal, binary_num, hex_num);
}
//---------------------------------------------------------------------------------------
//                              CONVERSION CHOICE
//---------------------------------------------------------------------------------------
void choice(int base1, int base2, int decimal, int binary_num[], char hex_num[])
{
    while (true)
    {
        // Asks for first base number
        printf("\n\nWhat base of number would you like to convert from? (2 : binary) (10 : decimal): ");
        scanf(" %d", &base1);

        // If valid base number
        if (base1 == 2 || base1 == 10 || base1 == 16)
        {
            system("cls || clear");

            printf("\n\nWhat base of number would you like to convert to? (2 : binary) (10 : decimal) (16: hex): ");
            scanf(" %d", &base2);

            // If valid base number
            if (base2 == 2 || base2 == 10 || base2 == 16)
            {

                if (base1 == 2 && base2 == 10)
                    binaryToDecimal(decimal, binary_num);
                else if (base1 == 10 && base2 == 2)
                    decimalToBinary(decimal, binary_num);
                else if (base1 == 10 && base2 == 16)
                    decimalToHex(decimal, hex_num);
                else if (base1 == 2 && base2 == 16)
                    binaryToHex(decimal, binary_num, hex_num);
                else
                    system("cls || clear");
            }
            // If invalid base number
            else
            {
                system("cls || clear");
                printf("\n\nThat is'nt a valid base number");
            }
        }

        // If invalid base number
        else
        {
            system("cls || clear");
            printf("\n\nThat is'nt a valid base number");
        }
    }
}
//---------------------------------------------------------------------------------------
//                          CONVERT DECIMAL TO BINARY
//---------------------------------------------------------------------------------------
void decimalToBinary(int decimal, int binary_num[])
{
    int *decimalPtr;
    decimalPtr = &decimal;

    int counter;

    int x = 0;

    system("cls || clear");

    printf("\n\tEnter a number whole number: ");
    scanf(" %d", &*decimalPtr);

    printf("\nThe decimal number %d is ", *decimalPtr);

    // Input Decimal is '0', binary number is '0'
    if (*decimalPtr == 0)
        printf("%d", *decimalPtr);

    // Loops until input decimal is smaller than '0'
    while (*decimalPtr > 0)
    {
        // Counter = remainder of input decimal
        counter = *decimalPtr % 2;

        // Adds either '1' or '0' to binary_num array
        binary_num[x] = counter;
        x++;

        // Divides input decimal by '2'
        *decimalPtr /= 2;
    }

    // Prints the binary_num in reverse order (while loop above adds '1' or '0' in reverse order)
    for (int i = x - 1; i >= 0; i--)
        printf("%d", binary_num[i]);

    printf(" in binary");
}
//---------------------------------------------------------------------------------------
//                          CONVERT DECIMAL TO HEXADECIMAL
//---------------------------------------------------------------------------------------
void decimalToHex(int decimal, char hex_num[])
{
    int *decimalPtr;
    decimalPtr = &decimal;

    int counter;

    int x = 0;

    system("cls || clear");

    printf("\n\tEnter a number whole number: ");
    scanf(" %d", &*decimalPtr);

    printf("\nThe decimal number %d is ", *decimalPtr);

    // Input Decimal is '0', hex number is '0'
    if (*decimalPtr == 0)
        printf("%d", *decimalPtr);

    // Loops until input decimal is smaller than '0'
    while (*decimalPtr > 0)
    {
        // Counter = remainder of input decimal
        counter = *decimalPtr % 16;

        // Depending on what the remainder of counter is, add the value to hex_num
        if (counter == 0)
            hex_num[x] = '0';

        else if (counter == 1)
            hex_num[x] = '1';

        else if (counter == 2)
            hex_num[x] = '2';

        else if (counter == 3)
            hex_num[x] = '3';

        else if (counter == 4)
            hex_num[x] = '4';

        else if (counter == 5)
            hex_num[x] = '5';

        else if (counter == 6)
            hex_num[x] = '6';

        else if (counter == 7)
            hex_num[x] = '7';

        else if (counter == 8)
            hex_num[x] = '8';

        else if (counter == 9)
            hex_num[x] = '9';

        else if (counter == 10)
            hex_num[x] = 'A';

        else if (counter == 11)
            hex_num[x] = 'B';

        else if (counter == 12)
            hex_num[x] = 'C';

        else if (counter == 13)
            hex_num[x] = 'D';

        else if (counter == 14)
            hex_num[x] = 'E';

        else if (counter == 15)
            hex_num[x] = 'F';

        x++;

        // Divides input decimal by '16'
        *decimalPtr /= 16;
    }
    // Prints the hex_num in reverse order (while loop above adds the values in reverse order)
    for (int i = x - 1; i >= 0; i--)
        printf("%c", hex_num[i]);

    printf(" in hexadecimal");
}
//---------------------------------------------------------------------------------------
//                          CONVERT BINARY TO DECIMAL
//---------------------------------------------------------------------------------------
void binaryToDecimal(int decimal, int binary_num[])
{

    int *decimalPtr;
    decimalPtr = &decimal;
    // The exponent used to calculate the decimal number
    int p = 0;
    // The input number
    char input[50];

    system("cls || clear");

    printf("\tEnter a binary number: ");
    scanf(" %s", &input);
    // Creates the exact size of input number
    int size = strlen(input);

    binary_num[size];

    printf("\nThe binary number ");
    // Divides all digits from num input and appends each to to a different element in the binary_num array
    for (int i = 0; i < size; i++)
    {
        binary_num[i] = *(input + i);
        printf("%c", binary_num[i]);
    }
    // Starts from the last element in binary_num array
    for (int i = size - 1; i >= 0; i--)
    {
        // char '0' = int 48
        if (binary_num[i] == 48)
        {
        }
        // char '1' = int 49
        else if (binary_num[i] == 49)
            // Decimal + 1 * 2^p e.g( binary number = 111 = (1 × 2²) + (1 × 2¹) + (1 × 2⁰) = (7))
            *decimalPtr = *decimalPtr + (1 * pow(2, p));
        // Adds 1 to p to calculate the decimal number
        p++;
    }
    printf(" is %d in decimal", *decimalPtr);
}
//---------------------------------------------------------------------------------------
//                          CONVERT BINARY TO HEXADECIMAL
//---------------------------------------------------------------------------------------
void binaryToHex(int decimal, int binary_num[], char hex_num[])
{
    int *decimalPtr;
    decimalPtr = &decimal;
    // The exponent used to calculate the decimal number
    int p = 0;
    // The input number
    char input[50];
    //
    // Binary to decimal
    //
    system("cls || clear");

    printf("\tEnter a binary number: ");
    scanf(" %s", &input);
    // Creates the exact size of input number
    int size = strlen(input);

    binary_num[size];

    printf("\nThe binary number ");
    // Divides all digits from num input and appends each to to a different element in the binary_num array
    for (int i = 0; i < size; i++)
    {
        binary_num[i] = *(input + i);
        printf("%c", binary_num[i]);
    }
    // Starts from the last element in binary_num array
    for (int i = size - 1; i >= 0; i--)
    {
        // char '0' = int 48
        if (binary_num[i] == 48)
        {
        }
        // char '1' = int 49
        else if (binary_num[i] == 49)
            // Decimal + 1 * 2^p e.g( binary number = 111 = (1 × 2²) + (1 × 2¹) + (1 × 2⁰) = (7))
            *decimalPtr = *decimalPtr + (1 * pow(2, p));
        // Adds 1 to p to calculate the decimal number
        p++;
    }
    printf(" is ");
    //
    // Decimal to Hex
    //
    int counter;

    int x = 0;
    // Input Decimal is '0', hex number is '0'
    if (*decimalPtr == 0)
        printf("%d", *decimalPtr);

    // Loops until input decimal is smaller than '0'
    while (*decimalPtr > 0)
    {
        // Counter = remainder of input decimal
        counter = *decimalPtr % 16;

        // Depending on what the remainder of counter is, add the value to hex_num
        if (counter == 0)
            hex_num[x] = '0';

        else if (counter == 1)
            hex_num[x] = '1';

        else if (counter == 2)
            hex_num[x] = '2';

        else if (counter == 3)
            hex_num[x] = '3';

        else if (counter == 4)
            hex_num[x] = '4';

        else if (counter == 5)
            hex_num[x] = '5';

        else if (counter == 6)
            hex_num[x] = '6';

        else if (counter == 7)
            hex_num[x] = '7';

        else if (counter == 8)
            hex_num[x] = '8';

        else if (counter == 9)
            hex_num[x] = '9';

        else if (counter == 10)
            hex_num[x] = 'A';

        else if (counter == 11)
            hex_num[x] = 'B';

        else if (counter == 12)
            hex_num[x] = 'C';

        else if (counter == 13)
            hex_num[x] = 'D';

        else if (counter == 14)
            hex_num[x] = 'E';

        else if (counter == 15)
            hex_num[x] = 'F';

        x++;

        // Divides input decimal by '16'
        *decimalPtr /= 16;
    }
    // Prints the hex_num in reverse order (while loop above adds the values in reverse order)
    for (int i = x - 1; i >= 0; i--)
        printf("%c", hex_num[i]);

    printf(" in hexadecimal");
}