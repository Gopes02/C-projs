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
    signed char sc = -7;
    unsigned char usc = sc;
    short sx = sc;
    unsigned short usx = sc;
    unsigned short usy = sx;
    int ty = sc;
    unsigned int uty = ty;


    printf("the decimal format is %d and the Hex format is %X of sc\n",sc,sc);
    printf("the decimal format is %d and the Hex format is %X of usc\n",usc,usc);
    printf("the decimal format is %d and the Hex format is %X of sx\n",sx,sx);
    printf("the decimal format is %d and the Hex format is %X of usx\n",usx,usx);
    printf("the decimal format is %d and the Hex format is %X of usy\n",usy,usy);
    printf("the decimal format is %d and the Hex format is %X of ty\n",ty,ty);
    printf("the decimal format is %u and the Hex format is %X of uty\n",uty,uty);
    
}