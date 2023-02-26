#include <stdio.h>

void string_input(char* str);
void string_length(char* str, int* len);
int lower_case_test(char c);
char lower_to_upper(char c);
void capitalize_alpha_chars(char* str, int* strLen,int* count);
void reverse_string(char* str, int* strLen, char* newStr );
void print(char* newStr, int* strLen, int* count);

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH], lower[MAX_LENGTH], newStr[MAX_LENGTH];
    int strLen = 0, count = 0;
    
    string_input(str);
    string_length(str, &strLen);
    capitalize_alpha_chars(str,&strLen,&count);
    reverse_string(str, &strLen, newStr);
    print( newStr, &strLen, &count);

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
