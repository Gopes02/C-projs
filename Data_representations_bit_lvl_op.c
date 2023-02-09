#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bitwiseOperations();
void sizeDataset();
unsigned int converting (char *input);

int main(){
    int choice;
    int flag = 1;

    while (flag){

        printf("Press 1 for: Bitwise operations\n");
        printf("Press 2 for: Data types and sizes\n");
        printf("Press 3 for: Converting number repesentations with different base\n");
        printf("Press 4 to Quit\n");
        printf("Please enter your Choice: ");
        scanf("%d",&choice);
        printf("\n\n\n\n");
    
        switch (choice){
            case 1:
                printf ("Bitwise operations\n\n");
                bitwiseOperations();
                break;
            case 2: 
                printf("Data types and sizes\n\n");
                sizeDataset();
                break;
            case 3: 
                printf("Converting number repesentations with different base/n");
                
                char input[50];
                printf("Enter a number in Hex/Dec/Bin: ");
                scanf("%s",input);

                int value = converting(input);
                printf("Hexadecimal: 0x%X\n", value);
                //Bin *****add*********
                printf("Octal: 0%o\n\n", value);
                
                break;
            case 4:
                printf("GoodBye");
                flag = 0;
                break;
            default: 
                printf("invalid input");
        }
    } 
    return 0;

}


void bitwiseOperations(){
   
    int a, b;

    printf("Please enter the int value of a: ");
    scanf("%d",&a);
    
    printf("Please enter the int value of b: ");
    scanf("%d",&b);

    //Prints or and xor
    printf("or: %d\n",(a|b));
    printf("xor: %d\n\n\n",(a^b));
}
void sizeDataset(){
    //Prints size of many data types uses (%lu) because it is unsigned long int 
    //sizeof() function gives size of chosen Data Type 
    printf("Size of char: %lu bytes\n", sizeof(char));
    printf("Size of short: %lu bytes\n", sizeof(short));
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of unsigned int: %lu bytes\n", sizeof(unsigned int));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of double: %lu bytes\n", sizeof(double));
    printf("Size of long double: %lu bytes\n", sizeof(long double));
}
unsigned int converting (char *input){
    int base = 10;
    char *endptr;
    unsigned int result;

    if (input[0] == 'b' || input[0] == 'B') {
        base = 2;
        input = input +1;
    } else if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        base = 16;
    } else{
        printf ("\nError: Unknown data type \n\n");
        return 0;
    }

    result = strtoul(input, &endptr, base);
    printf("\nNumber %s converted to unsigned int: %u\n", input, result);
    return result;
}

