#include <stdio.h>

void string_input(char* str);
void string_lenght(char* str, int* len);
int lower_case_test(char c);
char lower_to_upper(char c);
#define MAX_LENGHT 100

int main(){
    char str[MAX_LENGHT], lower[MAX_LENGHT];
    int strLen = 0;
    string_input(str);
    string_lenght(str, &strLen);
    
}

void string_input(char *str){
    
    printf("Enter a string: ");
    fgets(str,MAX_LENGHT,stdin);

    printf("%s",str);
}

void string_lenght(char* str, int* strLen){
    int i =0; 
    while( str[i] != '\0'){
        i++;
    }
    *strLen = i-1;
    printf("%d",*strLen);
}

int lower_case_test(char c){
    return (c >= 'a' && c<= 'z');
}

char lower_to_upper(char c){
    return c = c - 'a' + 'A';
}