#include <stdio.h>
#include <stdbool.h>

int aiBuffer[100];  //  stores the stack elements
int iNextIndex; //  points to the next to the top of the stack
int iCapacity;  //  stores the total capacity of stack

/*
    * gives the no of elements present in the stack
    *
    * return int
*/
int getSizeOfStack();

/*
    * checks if the stack is empty or not
    *
    * @return boolean
*/
bool isStackEmpty();

/*
    * adds elements at the top of the stack
    *
    * @param iElement is the value of element
    *
    * @return void
*/
void push(int iElement);

/*
    * deletes the element from the top of the stack
    *
    * @return int
*/
int pop();

/*
    * return the element present at the top of the stack
    *
    * @return int
*/
int getTopOfStack();

int getSizeOfStack()
{
    return iNextIndex;
}

bool isStackEmpty()
{
    if (iNextIndex == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(int iElement)
{
    if (iNextIndex == iCapacity)
    {
        printf("Stack Full\n");
        return;
    }

    aiBuffer[iNextIndex] = iElement;
    iNextIndex++;
}

int pop()
{
    if (isStackEmpty())
    {
        printf("Stack empty\n");

        return -1;
    }

    iNextIndex--;

    return aiBuffer[iNextIndex];
}

int getTopOfStack()
{
    if (isStackEmpty())
    {
        printf("Stack empty\n");

        return -1;
    }

    return aiBuffer[iNextIndex - 1];
}


