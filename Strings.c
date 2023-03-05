#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isSubstring(char string[], char substring[]) {
    int string_len = strlen(string);
    int substring_len = strlen(substring);
    int i, j;
    int found = 0;
    
    // Convert both strings to lowercase for case-insensitive search
    for (i = 0; i < string_len; i++) {
        string[i] = tolower(string[i]);
    }
    
    for (i = 0; i < substring_len; i++) {
        substring[i] = tolower(substring[i]);
    }
    
    // Iterate over string and check for substring
    for (i = 0; i < string_len; i++) {
        found = 1;
        for (j = 0; j < substring_len; j++) {
            if (string[i+j] != substring[j]) {
                found = 0;
                break;
            }
        }
        if (found) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char string[100];
    char substring[100];

    printf("Enter a string: ");
    scanf("%[^\n]s", string);

    printf("Enter a substring: ");
    scanf(" %[^\n]s", substring);

    if (isSubstring(string, substring)) {
        printf("The substring '%s' is present in the string '%s'.\n", substring, string);
    } else {
        printf("The substring '%s' is not present in the string '%s'.\n", substring, string);
    }

    return 0;
}
