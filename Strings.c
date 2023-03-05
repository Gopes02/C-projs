#include <stdio.h>
#include <string.h>
#include <ctype.h>

int charCountsEqual(char str[], char substr[]);
int isSubstring(char str[], char substr[]);
void splitString(char str[], char words[][100], int *numWords);

int main() {
    char string[100];
    char substring[100];
    char words[20][100];
    int numWords;

    printf("Enter a string: ");
    scanf("%[^\n]", string);
    getchar();

    printf("Enter a substring: ");
    scanf("%[^\n]", substring);
    getchar();

    if (isSubstring(string, substring))
        printf("Substring exists in the given string.\n");
    else
        printf("Substring does not exist in the given string.\n");

    if (charCountsEqual(string, substring)) {
        printf("The strings have the same number of character counts.\n");
    } else {
        printf("The strings do not have the same number of character counts.\n");
    }

    splitString(string, words, &numWords);

    printf("The string split into words:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}

int isSubstring(char str[], char substr[]) {
    int strLen = strlen(str);
    int substrLen = strlen(substr);

    for (int i = 0; i <= strLen - substrLen; i++) {
        int j;

        for (j = 0; j < substrLen; j++) {
            if (tolower(str[i + j]) != tolower(substr[j]))
                break;
        }

        if (j == substrLen)
            return 1;
    }

    return 0;
}

int charCountsEqual(char str[], char substr[]) {
    int counts1[26] = {0}, counts2[26] = {0};
    int i;

    for (i = 0; i < strlen(str); i++) {
        if (isalpha(str[i])) {
            counts1[tolower(str[i]) - 'a']++;
        }
    }
    for (i = 0; i < strlen(substr); i++) {
        if (isalpha(substr[i])) {
            counts2[tolower(substr[i]) - 'a']++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (counts1[i] != counts2[i]) {
            return 0;
        }
    }

    return 1;
}

void splitString(char str[], char words[][100], int *numWords) {
    *numWords = 0;
    char *word = strtok(str, " ");

    while (word != NULL && *numWords < 20) {
        strcpy(words[*numWords], word);
        (*numWords)++;
        word = strtok(NULL, " ");
    }
}
