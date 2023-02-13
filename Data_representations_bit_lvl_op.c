#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void bitwiseOperations();
void sizeDataset();
void intToBinary(int num);
unsigned int converting (char *input);

    //My code is different from the sample code given for the lab because I wanted practice doing everything myself 
    

int main(){
    int choice;
    // Flag is used to end the program 
    int flag = 1;
    // Int the while loop you will have the option to choose between  Bitwise operations, data types and sizes, and Converting number representations w/ diffrent base 
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
                // Take in the user input for number in Hex/Dec/Bin  
                char input[50];
                printf("Enter a number in Hex/Dec/Bin: ");
                scanf("%s",input);
                // We run the converting function (with the input the user has entered), converting function returns a value which becomes the value for value  
                int value = converting(input);
                // %X prints the unsigned int in Hexadecimal format 
                printf("Hexadecimal: 0x%X\n", value);
                // To convert unsigned int to binary we run the function dec
                intToBinary(value);
                // %o prints the unsigned int in octal format 
                printf("Octal: 0%o\n\n", value);
                
                break;
            case 4:
                // changes the value of Flag and this exits the program
                printf("GoodBye");
                flag = 0;
                break;
            // Any value that is not between 1-4 will result in an invalid input and asks the user to enter a new value 
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
    // input is taken from main
    // the orig base value of 8 has no meaning, it will be changed  
    int base = 8;
    // pointer to the first character that is not part of the number being converted 
    char *endptr;
    unsigned int result;
    // if the input starts with B or b, bin 
    if (input[0] == 'b' || input[0] == 'B') {
        //the base is changed to 2 
        //we start the input number with element two of the array because otherwise converstion would return as 0 
        base = 2;
        input = input +1;
    // if it starts with 0x or 0X, hex 
    } else if (input[0] == '0' && (input[1] == 'x' || input[1] == 'X')) {
        base = 16;
    // if it starts with at least 0 and at most 9 and isnt the previous if statements, dec
    }else if (input[0] >= '0' && input[0] <= '9'){
         base = 10;
    // If none of the if statments run meaning then prints out there was an error and ends the function 
    } else{
        printf ("\nError: Unknown data type \n\n");
        return 0;
    }
    //strtoul does the conversion to unsigned int using the input user entered (A pointer to the string representation of the number.), endptr (explained above), and base (depends on the if statement)
    result = strtoul(input, &endptr, base);
    printf("\nNumber %s converted to unsigned int: %u\n", input, result);
    return result;
}
// Function to convert unsigned int to Bin
void intToBinary(int num) {   
    if (num == 0) {
        printf("0");
        return;
    }
   
   // Stores binary representation of number. Assuming 32 bit integer.
   int binaryNum[32];
   int i=0;
   
   for (i=0 ;num > 0; ){
      binaryNum[i++] = num % 2;
      num /= 2;
   }
   
   
   printf("Binary: b");
   // Printing array in reverse order.
   for (int j = i-1; j >= 0; j--){
      
      printf("%d", binaryNum[j]);
   }
   printf("\n");
}
