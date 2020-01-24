/*Program to perform various stack operations*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void main ()
{
    int iElement;
    iCapacity = 5;

    while(1)
    {   
        int iChoice;

        /*menu for stack operations*/
        printf("Stack Operations Menu\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. No of elements in stack\n");
        printf("4. Print top of stack\n");
        printf("5. Print stack\n");
        printf("0. Exit\n");
        printf("Make a selection    : ");
        scanf("%d", &iChoice);

        switch(iChoice)
        {
            case 0:
                    /*program termination*/
                    exit(0);

            case 1:
                    /*push*/
                    printf("Enter the value to push : ");
                    scanf("%d", &iElement);
                    push(iElement);
                    break;

            case 2:
                    /*pop*/
                    printf("%d popped\n", pop());
                    break;

            case 3:
                    /*no of elements in stack*/
                    printf("No of elements in queue : %d\n", getSizeOfStack());
                    break;

            case 4:
                    /*gets the front element of stack*/
                    printf("Top element   : %d\n", getTopOfStack());
                    break;
            
            case 5:
                    /*print queue*/
                    printStack();
                    break;

            default:
                    printf("Invalid Selection!\n");
                    break;
        }
        printf("\n");
    }
}
