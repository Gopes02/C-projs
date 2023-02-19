#include <stdio.h>

void displayFunction();

int main(){
    int choice, flag = 1;


    while (flag){
        printf("Press 1: to display in hex and Dec Format: \n");
        printf("press 2: part 2: \n");
        printf("Press 3: To quit\n\n");

        scanf("%d",&choice);
        switch (choice){
            case 1: 
                printf("Displaying in hex and Dec format\n");
                displayFunction();
                break;
            case 2: 
                printf("Part 2");

                break;
            case 3: 
                flag = 2;
                printf("GoodBye");
                break;
            default:
                printf("Invalid input");
        }
    }
}

void displayFunction(){

    
}