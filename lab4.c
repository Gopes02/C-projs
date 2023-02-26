#include <stdio.h>

void string_input(char* str);
void string_length(char* str, int* len);
int lower_case_test(char c);
char lower_to_upper(char c);
void capitalize_alpha_chars(char* str, int* strLen,int* count);
void reverse_string(char* str, int* strLen, char* newStr );
void print(char* newStr, int* strLen, int* count);
int SortAndFind(int *Arr, int X);

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH], lower[MAX_LENGTH], newStr[MAX_LENGTH];
    int strLen = 0, count = 0;
    
    string_input(str);
    string_length(str, &strLen);
    capitalize_alpha_chars(str,&strLen,&count);
    reverse_string(str, &strLen, newStr);
    print( newStr, &strLen, &count);

    printf("\n-------------------------------------------------------------------------\n");
    int Arr[MAX_LENGTH] = {0};
    int i = 0, X = 0;
    
    while (i < MAX_LENGTH) {
        printf("Enter an element of the array (to end the array enter '-1'): ");  
        scanf("%d", &Arr[i]);
        
        if (Arr[i] == -1) {
            break;
        } 
        i++;
    }

    printf("Please enter the int you are looking for in the array: ");
    scanf("%d", &X);
    
    int index = SortAndFind(Arr, X);
    if (index == -1) {
        printf("%d was not found in the array\n", X);
    } else {
        printf("%d was found at index %d in the sorted array\n", X, index);
    }
    return 0;
}

void string_input(char *str) {
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
}

void string_length(char* str, int* strLen) {
    int i = 0; 
    while (str[i] != '\0') {
        i++;
    }
    *strLen = i - 1;
}

int lower_case_test(char c) {
    return (c >= 'a' && c <= 'z');
}

char lower_to_upper(char c) {
    return c - 'a' + 'A';
}

void capitalize_alpha_chars(char* str, int* strLen, int* count) {
    for (int i = 0; i < *strLen; i++) {
        if (lower_case_test(str[i])) {
            str[i] = lower_to_upper(str[i]);
            (*count)++;
        }
    }
}

void reverse_string(char* str, int* strLen, char* newStr) {
    int j = *strLen - 1;

    for (int i = 0; i < *strLen; i++, j--) {
        newStr[i] = str[j];
    }
    newStr[*strLen] = '\0';
}

void print(char* newStr, int* strLen, int* count) {
    for (int i = 0; i < *strLen; i++) {
        printf("%c\n", newStr[i]);
    }
     printf("The string is %d chars and %d chars were capitalized. ", *strLen, *count);

}


int SortAndFind(int *Arr, int X) {
    int len = 0;
    while (Arr[len] != -1) {
        len++;
    }

    // Bubble Sort algorithm
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (Arr[j] > Arr[j+1]) {
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
    
 
    printf("Sorted Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");


    int left = 0;
    int right = len - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (Arr[mid] == X) {
            return mid;
        } else if (Arr[mid] < X) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1;
}
