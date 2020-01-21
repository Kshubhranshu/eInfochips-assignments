#include <stdio.h>
#include <stdbool.h>

int iaQueueData[10];
int iNextIndex = 0;
int iFirstIndex = - 1;
int iSize = 0;
int iMaxCapacity;

int getSize();
bool isEmpty();
void enqueue(int iElement);
int getFrontElement();
int dequeue();
void printQueue();

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
    iaQueueData[iNextIndex] = iElement;
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
    return iaQueueData[iFirstIndex];
}

int dequeue()
{   int iDeletedElement;
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return 0;
    }
    iDeletedElement = iaQueueData[iFirstIndex];
    iFirstIndex = (iFirstIndex + 1) % iMaxCapacity;
    iSize--;
    return iDeletedElement;
}

void printQueue()
{
    ku
}