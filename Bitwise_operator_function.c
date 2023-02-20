#include <stdio.h>
#include <stdlib.h>

void displayFunction();
void bitFunction();
char* decToBin(int num);
int main(){
    int choice, flag = 1;


    while (flag != 2){
        printf("Press 1: to display in hex and Dec Format: \n");
        printf("press 2: part 2: \n");
        printf("Press 3: To quit\n\n");

        scanf("%d",&choice);
        switch (choice){
            case 1: 
                printf("Displaying in hex and Dec format\n");
                displayFunction();
                break;
            case 2: 
                printf("Part 2\n");
                bitFunction();
                break;
            case 3: 
                flag = 2;
                printf("GoodBye");
                break;
            default:
                printf("Invalid input");
        }
    }
}

void displayFunction(){
    signed char sc = -7;
    unsigned char usc = sc;
    short sx = sc;
    unsigned short usx = sc;
    unsigned short usy = sx;
    int ty = sc;
    unsigned int uty = ty;


    printf("the decimal format is %d and the Hex format is %X of sc\n",sc,sc);
    printf("the decimal format is %d and the Hex format is %X of usc\n",usc,usc);
    printf("the decimal format is %d and the Hex format is %X of sx\n",sx,sx);
    printf("the decimal format is %d and the Hex format is %X of usx\n",usx,usx);
    printf("the decimal format is %d and the Hex format is %X of usy\n",usy,usy);
    printf("the decimal format is %d and the Hex format is %X of ty\n",ty,ty);
    printf("the decimal format is %u and the Hex format is %X of uty\n",uty,uty);
    
}

void bitFunction(){
    long int A, B, C, D, E;
   
    
    printf("Please enter the value of A: ");
    scanf("%ld",&A);
    printf("Please enter the value of B: ");
    scanf("%ld",&B);
    
    C = A|B; //OR
    D = A^B; //Xor
    E = A&B; //And 
   //needed to use function decToBin to convert to Bin
    printf("\nThe Bitwise OR of  A: %ld and B: %ld is %s in Binary\n",A,B,decToBin(C));
    printf("The Bitwise Xor of A: %ld and B: %ld is %s in Binary\n",A,B,decToBin(D));
    printf("The Bitwise AND of A: %ld and B: %ld is %s in Binary\n\n\n",A,B,decToBin(E));
}


char* decToBin(int num){
    static char bin[33]; // 32 bits + 1 null terminator, static so it isnt re-initialized
    int i = 0;
    
    if(num == 0) { 
        bin[0] = '0';
        bin[1] = '\0';
        return bin; // returns 0 if num = 0;
    }
    
    while(num > 0){
        bin[i++] = (num & 1) + '0'; //results in either 0 or 1, then converts to ASCII character 
        num >>= 1;
    }
    bin[i] = '\0';
    // reverse the binary string to correct order
    int j = 0, k = i - 1;
    while(j < k){
        char temp = bin[j];
        bin[j] = bin[k];
        bin[k] = temp;
        j++;
        k--;
    }
    
    return bin;
}

