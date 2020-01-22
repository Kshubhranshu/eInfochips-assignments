#include <stdio.h>
#include <stdbool.h>

int aiBuffer[100];
int iNextIndex;
int iCapacity;

/*return the number of elements present in the stack*/
int getSizeOfStack()
{
    return iNextIndex;
}

/*checks that if the stack is empty or not*/
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

/*adds element at the top of stack*/
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

/*deletes element from the top of stack*/
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

/*returns the top of stack*/
int getTopOfStack()
{
    if (isStackEmpty())
    {
        printf("Stack empty\n");
        return -1;
    }

    return aiBuffer[iNextIndex - 1];
}


