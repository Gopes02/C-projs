#include <stdio.h>

void int_to_bin(int n, int bin[]);
void remove_leading_zeros(int binary[], int* size);
void compare_size(int sizeA, int sizeB, int* sizeC);
void bitwise_or(int binaryA[],int binaryB[], int binaryC[], int sizeC);
void bitwise_xor(int binaryA[],int binaryB[], int binaryC[], int sizeC);
void bitwise_and(int binaryA[],int binaryB[], int binaryC[], int sizeC);

int main(){

    int A, B;
    int binaryA[32] = {0}, binaryB[32] = {0}, newBinaryA[32] = {0}, newBinaryB[32] = {0};
    int binaryOr[32]={0}, binaryXor[32]={0},binaryAnd[32]={0};
    int sizeA = 32, sizeB = 32, sizeC = 32;
    
    printf("Pick the value of A: ");
    scanf("%d", &A);
    int_to_bin(A, binaryA);
    remove_leading_zeros(binaryA, &sizeA);
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
    for (int i = sizeA-1; i >= 0; i--) {
        printf("%d", newBinaryA[i]);
    }
    printf("\n");

    printf("Binary representation of B: ");
    for (int i = sizeB-1; i >= 0; i--) {
        printf("%d", newBinaryB[i]);
    }
    printf("\n");

   printf("Binary representation of Or: ");
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

void int_to_bin(int n, int bin[]) {
    int i = 0;
    while (n > 0) {
        bin[i++] = n % 2;
        n /= 2;
    }
  
}

void remove_leading_zeros(int binary[], int* size){
    int i = *size - 1;
    while (binary[i] == 0 && i > 0){
        i--;
    }
    *size = i + 1;
}

void compare_size(int sizeA, int sizeB, int* sizeC){
    if(sizeA >= sizeB){
        *sizeC = sizeA; 
    } else{
        *sizeC = sizeB;
    }
}


void bitwise_or(int binaryA[],int binaryB[], int binaryC[], int size){
    for(int i = size-1; i>=0;i-- ){
        if(binaryA[i]== 1 || binaryB[i]== 1){
            binaryC[i] = 1;
        } else{
            binaryC[i]=0;
        }
    }
}


void bitwise_xor(int binaryA[],int binaryB[], int binaryC[], int size){
    for(int i = size-1; i>=0;i-- ){
        if((binaryA[i]== 1 && binaryB[i]== 0) || (binaryA[i]== 0 && binaryB[i]== 1)){
            binaryC[i] = 1;
        } else{
            binaryC[i]=0;
        }
    }
}

void bitwise_and(int binaryA[],int binaryB[], int binaryC[], int size){
    for(int i = size-1; i>=0;i-- ){
        if(binaryA[i]== 1 && binaryB[i]== 1){
            binaryC[i] = 1;
        } else{
            binaryC[i]=0;
        }
    }
}