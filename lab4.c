#include <stdio.h>

void string_input(char* str);
void string_lenght(char* str, int* len);
int lower_case_test(char c);
char lower_to_upper(char c);
void capitalize_alpha_chars(char* str, int* strLen,int* count);
void reverse_string(char* str, int* strLen);
#define MAX_LENGHT 100

int main(){
    char str[MAX_LENGHT], lower[MAX_LENGHT];
    int strLen = 0, count = 0;
    string_input(str);
    string_lenght(str, &strLen);
    capitalize_alpha_chars(str,&strLen,&count);
    reverse_string(str, &strLen);

}

void string_input(char *str){
    
    printf("Enter a string: ");
    fgets(str,MAX_LENGHT,stdin);

}

void string_lenght(char* str, int* strLen){
    int i =0; 
    while( str[i] != '\0'){
        i++;
    }
    *strLen = i-1;
    
}

int lower_case_test(char c){
    return (c >= 'a' && c<= 'z');
}

char lower_to_upper(char c){
    return c = c - 'a' + 'A';
}

void capitalize_alpha_chars(char* str, int* strLen,int* count){
    for (int i=0;i < *strLen;i++ ){
        if(lower_case_test(str[i])){
            lower_to_upper(str[i]);
            (*count)++;
        }
    }
}

void reverse_string(char* str, int* strLen){
    int i = 0;
    int j = *strLen;

    while(i<j){
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
