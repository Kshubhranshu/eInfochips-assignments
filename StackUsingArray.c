/*Program to perform various stack operations*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#define RED printf("\x1b[31;40m");
#define RESET printf("\x1b[m");


void main ()
{
    int iElement;

    printf("Enter the capacity of stack[max cap: 100] : ");
    scanf("%d", &iCapacity);

    /*validate capacity*/
    if(iCapacity > N)
    {
        RED
        printf("Maximum capacity limit exceeded!!!\n");
        RESET
        
        exit(0);
    }

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
                    printf("No of elements in stack : %d\n", getSizeOfStack());
                    break;

            case 4:
                    /*gets the top of stack*/
                    printf("Top element   : %d\n", getTopOfStack());
                    break;
            
            case 5:
                    /*print queue*/
                    printStack();
                    break;

            default:
                    /*invalid input*/
                    printf("Invalid Selection!\n");
                    break;
        }
        printf("\n");
    }
}
