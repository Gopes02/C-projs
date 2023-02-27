#include <stdio.h>

void string_input(char* str);
void string_length(char* str, int* len);
int lower_case_test(char c);
char lower_to_upper(char c);
void capitalize_alpha_chars(char* str, int* strLen,int* count);
void reverse_string(char* str, int* strLen, char* newStr );
void print(char* newStr, int* strLen, int* count);
int SortAndFind(int *Arr, int X);
int match_content(char *file1, char *file2); // not called in main since we were only asked to make a function 

#define MAX_LENGTH 100
#define BUFFER_SIZE 4096


//Since main is mostly just calling the functions I didnt comment anything in main 

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

     printf("\n-------------------------------------------------------------------------\n");
    /*
    char file1[] = "file1.txt";
    char file2[] = "file2.txt";

    int result = match_content(file1, file2);

    if (result == 1) {
        printf("The content in the files is the same.\n");
    } else {
        printf("The content in the files is different.\n");
    }

    */


    return 0;
}
//Function to the the string from the user
void string_input(char *str) {
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
}
//function to find the string lenght 
void string_length(char* str, int* strLen) {
    int i = 0; 
    while (str[i] != '\0') {
        i++;
    }
    *strLen = i - 1;
}
//checks if the char is lower case, if it is between a and z it lower case 
int lower_case_test(char c) {
    return (c >= 'a' && c <= 'z');
}
//char - a finds the diffrence between the char and a and when A is added the same letter but capitalized is printed
char lower_to_upper(char c) {
    return c - 'a' + 'A';
}
//if the char qualifys for lower_case_test then we use lower_to_upper function to capitalize it and increase the number of char capitalized
void capitalize_alpha_chars(char* str, int* strLen, int* count) {
    for (int i = 0; i < *strLen; i++) {
        if (lower_case_test(str[i])) {
            str[i] = lower_to_upper(str[i]);
            (*count)++;
        }
    }
}
//we use a new array to take in the orginal array backwards, New array is assending while old array is desending 
void reverse_string(char* str, int* strLen, char* newStr) {
    int j = *strLen - 1;

    for (int i = 0; i < *strLen; i++, j--) {
        newStr[i] = str[j];
    }
    newStr[*strLen] = '\0';
}
//for loop to print new array, just pluging in variables using pointers
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

    // Bubble Sort algorithm to sort the array from smallest to largest 
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-i-1; j++) {
            if (Arr[j] > Arr[j+1]) {
                int temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
    
    // printing the new array
    printf("Sorted Array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", Arr[i]);
    }
    printf("\n");

    //Looks for the X using binary serch 
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


int match_content(char *file1, char *file2) {
    FILE *f1, *f2;
    char buffer1[BUFFER_SIZE], buffer2[BUFFER_SIZE];
    int bytes_read1, bytes_read2;

    f1 = fopen(file1, "rb");
    if (f1 == NULL) {
        printf("Error opening file1.\n");
        return 0;
    }

    f2 = fopen(file2, "rb");
    if (f2 == NULL) {
        printf("Error opening file2.\n");
        fclose(f1);
        return 0;
    }

    while (((bytes_read1 = fread(buffer1, 1, BUFFER_SIZE, f1)) > 0)
           && ((bytes_read2 = fread(buffer2, 1, BUFFER_SIZE, f2)) > 0)) {

        // Compare the bytes read from the two files, ignoring case
        for (int i = 0; i < bytes_read1; i++) {
            if (buffer1[i] != buffer2[i] && (buffer1[i] ^ 32) != buffer2[i]) {
                fclose(f1);
                fclose(f2);
                return 0;
            }
        }
    }

    // If both files have reached EOF, they are the same
    if (feof(f1) && feof(f2)) {
        fclose(f1);
        fclose(f2);
        return 1;
    }

    // If one file has reached EOF but the other hasn't, they are different
    fclose(f1);
    fclose(f2);
    return 0;
}