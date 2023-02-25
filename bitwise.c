#include <stdio.h>

void int_to_bin(int n, int bin[]);
void remove_leading_zeros(int binary[], int* size);

int main(){

    int A, B;
    int binaryA[32] = {0}, binaryB[32] = {0}, newBinaryA[32] = {0}, newBinaryB[32] = {0};
    int sizeA = 32, sizeB = 32;
    
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
