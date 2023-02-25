#include <stdio.h>

void int_to_bin(int n, int bin[]);  
void remove_leading_zeros(int binary[], int* size);
void compare_size(int sizeA, int sizeB, int* sizeC); 
void bitwise_or(int binaryA[],int binaryB[], int binaryC[], int sizeC);
void bitwise_xor(int binaryA[],int binaryB[], int binaryC[], int sizeC);
void bitwise_and(int binaryA[],int binaryB[], int binaryC[], int sizeC);

int main(){

    int A, B;
    int binaryA[32] = {0}, binaryB[32] = {0};
    int newBinaryA[32] = {0}, newBinaryB[32] = {0}; //used newBinary for new array after removing leading zeros
    int binaryOr[32]={0}, binaryXor[32]={0},binaryAnd[32]={0};
    int sizeA = 32, sizeB = 32, sizeC = 32; 

    printf("Pick the value of A: ");
    scanf("%d", &A);
    int_to_bin(A, binaryA); 
    remove_leading_zeros(binaryA, &sizeA); //
    for(int i=0; i<sizeA; i++){
        newBinaryA[i] = binaryA[i];
    }
    
    printf("Pick the value of B: ");
    scanf("%d", &B);
    int_to_bin(B, binaryB);
    remove_leading_zeros(binaryB, &sizeB);
    for(int i=0; i<sizeB; i++){
        newBinaryB[i] = binaryB[i];
    }

    compare_size(sizeA,sizeB,&sizeC);
    
    bitwise_or(newBinaryA,newBinaryB, binaryOr, sizeC);
    bitwise_xor(newBinaryA,newBinaryB, binaryXor, sizeC);
    bitwise_and(newBinaryA,newBinaryB, binaryAnd, sizeC);

    printf("Binary representation of A: ");
    printf("  ");  //Added space to even out 
    for (int i = sizeC-1; i >= 0; i--) {
        printf("%d", newBinaryA[i]);
    }
    printf("\n");

    printf("Binary representation of B: ");
    printf("  ");  //Added space to even out 
    for (int i = sizeC-1; i >= 0; i--) {
        printf("%d", newBinaryB[i]);
    }
    printf("\n");

   printf("Binary representation of Or: ");
   printf(" "); //Added space to even out 
    for (int i = sizeC-1; i >= 0; i--) {
        printf("%d", binaryOr[i]);
    }
    printf("\n");

    printf("Binary representation of Xor: ");
    for (int i = sizeC-1; i >= 0; i--) {
        printf("%d", binaryXor[i]);
    }
    printf("\n");

    printf("Binary representation of And: ");
    for (int i = sizeC-1; i >= 0; i--) {
        printf("%d", binaryAnd[i]);
    }
    printf("\n");

    return 0;
}
// converts int to binary. by placing each value as an element of the array  

void int_to_bin(int n, int bin[]) {
    int i = 0;
    while (n > 0) {
        bin[i++] = n % 2;
        n /= 2;
    }
  
}
// removes leading zeros in the array, but it will keep some leading zeros if one of the arrays are bigger than other, so the arrays look balanced when printed 
void remove_leading_zeros(int binary[], int* size){
    int i = *size - 1;
    while (binary[i] == 0 && i > 0){
        i--;
    }
    *size = i + 1;
}
// Comapre the size of the arrays, we use the size that is bigger. 
void compare_size(int sizeA, int sizeB, int* sizeC){
    if(sizeA >= sizeB){
        *sizeC = sizeA; 
    } else{
        *sizeC = sizeB;
    }
}

// compares the arrays element by element and creates a new array
// if either one of the array for that element has a '1' then the new array will also have an '1' for the same element other wise a '0'
void bitwise_or(int binaryA[],int binaryB[], int binaryC[], int size){
    for(int i = size-1; i>=0;i-- ){
        if(binaryA[i]== 1 || binaryB[i]== 1){
            binaryC[i] = 1;
        } else{
            binaryC[i]=0;
        }
    }
}

// compares the arrays element by element and creates a new array
// if one array for that element has a '1' and the other array has a '0' for the same element in the arry then the new array will also have an '1' for the same element 
// other wise a '0' for the same element
void bitwise_xor(int binaryA[],int binaryB[], int binaryC[], int size){
    for(int i = size-1; i>=0;i-- ){
        if((binaryA[i]== 1 && binaryB[i]== 0) || (binaryA[i]== 0 && binaryB[i]== 1)){
            binaryC[i] = 1;
        } else{
            binaryC[i]=0;
        }
    }
}
// compares the arrays element by element and creates a new array
// if both of the arrays for that element has a '1' then the new array will also have an '1' for the same element other wise a '0' for the same element
void bitwise_and(int binaryA[],int binaryB[], int binaryC[], int size){
    for(int i = size-1; i>=0;i-- ){
        if(binaryA[i]== 1 && binaryB[i]== 1){
            binaryC[i] = 1;
        } else{
            binaryC[i]=0;
        }
    }
}