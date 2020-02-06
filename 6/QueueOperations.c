/*Program to perform various queue operations*/
#include <stdio.h>
#include <stdlib.h>
#define N 100

/*will make sure to not use global variables from next time*/
int aiQueueData[N];    //  queue for storing values
int iNextIndex = 0;     //  stores the rear of the queue
int iFirstIndex = - 1;  //  stores the front of the queue
int iSize = 0;          //  stores the no of elements present in queue currently
int iMaxCapacity;       //  maximum capacity of queue

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

int isEmpty();

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

/*
    * prints the queue
    *
    * @return void
*/
void printQueue();

void main()
{
    iMaxCapacity = 5;
    int iValue;

    while(1)
    {   
        int iChoice;

        /*menu for array insertion operations*/
        printf("Queue Operations Menu\n");
        printf("1. Insert element\n");
        printf("2. Delete element\n");
        printf("3. No of elements in Queue\n");
        printf("4. Print front element\n");
        printf("5. Print queue\n");
        printf("0. Exit\n");
        printf("Make a selection    : ");
        scanf("%d", &iChoice);
		
		/*check whether the queue max limit reached*/
		if((iSize == iMaxCapacity) && iChoice == 1)
		{
			printf("Queue full, cannot insert more elements\n");
			break;
		}

        switch(iChoice)
        {
            case 0:
                    /*program termination*/
                    exit(0);

            case 1:
                    /*enqueue*/
                    printf("Enter the value to insert : ");
                    scanf("%d", &iValue);
                    enqueue(iValue);
                    break;

            case 2:
                    /*dequeue*/
					if(dequeue() == 0)
					{
						dequeue();
						break;
					}
                    printf("%d deleted\n", dequeue());
                    break;

            case 3:
                    /*no of elements in queue*/
                    printf("No of elements in queue : %d\n", getSize());
                    break;

            case 4:
                    /*gets the front element of queue*/
					if(getFrontElement() == 0)
					{
						getFrontElement();
						break;
					}
                    printf("Front element   : %d\n", getFrontElement());
                    break;
            
            case 5:
                    /*print queue*/
                    printQueue();
                    break;

            default:
                    printf("Invalid Selection!\n");
                    break;
        }
        printf("\n");
    }
}

int getSize()
{
    return iSize;
}

int isEmpty()
{
    if(iSize == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int iElement)
{
    if(iSize == iMaxCapacity)
    {
        printf("Queue full!!!\n");
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
        printf("Queue is empty!!\n");
        return 0;
    }

    return aiQueueData[iFirstIndex];
}

int dequeue()
{   
    int iDeletedElement;

    if (isEmpty())
    {
        printf("Queue is empty!!\n");
        return 0;
    }

    iDeletedElement = aiQueueData[iFirstIndex];
    iFirstIndex = (iFirstIndex + 1) % iMaxCapacity;
    iSize--;

    return iDeletedElement;
}

void printQueue()
{
    int iIndex;

    if(isEmpty())
    {
        printf("Nothing to print Queue empty\n");
        
    }
    else
    {
			for(iIndex = iFirstIndex; iIndex < iSize; iIndex++)
			{
				printf("[%d]", aiQueueData[iIndex]);
			}

			for(iIndex = 0; iIndex < iFirstIndex; iIndex++)
			{
				printf("[%d]", aiQueueData[iIndex]);
			}
    }
    printf("\n");
}
