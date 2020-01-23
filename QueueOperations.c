#include <stdio.h>
#include <stdbool.h>

int aiQueueData[10];    //  queue for storing values
int iNextIndex = 0;     
int iFirstIndex = - 1;  
int iSize = 0;
int iMaxCapacity;   

/*
    * gives the no of elements present in the queue
    *
    * @return int
*/
int getSize();

/*
    * checks if the queue is empty or not
    *
    * @return boolean
*/
bool isEmpty();

/*
    * adds new element in the queue at from the end
    *
    * @param iElement is the value of element
    *
    * @return void
*/
void enqueue(int iElement);

/*
    * gives the element value present at the begining of the queue
    *
    * @return int
*/
int getFrontElement();

/*
    * deletes the element from start of the queue and returns it
    *
    * @return int
*/
int dequeue();

void main()
{
    iMaxCapacity = 5;
    enqueue(10);  
    enqueue(50);  
    enqueue(30);  
    enqueue(60);  
    enqueue(60);  
    enqueue(70);  
}

int getSize()
{
    return iSize;
}

bool isEmpty()
{
    if(iSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(int iElement)
{
    if(iSize == iMaxCapacity)
    {
        printf("Queue full\n");
        return;
    }

    aiQueueData[iNextIndex] = iElement;
    
    iNextIndex = (iNextIndex + 1) % iMaxCapacity;
    
    if(iFirstIndex == -1)
    {
        iFirstIndex = 0;
    }

    iSize++;
}

int getFrontElement()
{
    if(isEmpty())
    {
        printf("Queue is empty\n");
        return 0;
    }

    return aiQueueData[iFirstIndex];
}

int dequeue()
{   
    int iDeletedElement;

    if (isEmpty())
    {
        printf("Queue is empty\n");
        return 0;
    }

    iDeletedElement = aiQueueData[iFirstIndex];
    iFirstIndex = (iFirstIndex + 1) % iMaxCapacity;
    iSize--;

    return iDeletedElement;
}
