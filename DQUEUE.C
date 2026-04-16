// DOUBLE ENDED QUEUE (DEQUE) //
#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // Required for exit()

#define max 5

int rear = 0;
int front = 0;
int queue[max + 1]; // Size max+1 to safely handle 1-based indexing

// Function Prototypes
void rinsert(); // Insert from Right (Rear)
void ldelete(); // Delete from Left (Front)
void rdelete(); // Delete from Right (Rear)
void linsert(); // Insert from Left (Front)
void disp();    // Display Queue

int main()
{
    int choice;
    // clrscr();

    // Using a while loop instead of goto for cleaner structure
    while(1)
    {
        printf("\n--- Double Ended Queue Operations ---");
        printf("\n1. Right Insert (Rear)");
        printf("\n2. Left Delete (Front)");
        printf("\n3. Right Delete (Rear)");
        printf("\n4. Left Insert (Front)");
        printf("\n5. Exit");
        printf("\n6. Display Queue");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: rinsert(); disp(); break;
            case 2: ldelete(); disp(); break;
            case 3: rdelete(); disp(); break;
            case 4: linsert(); disp(); break;
            case 5: exit(0);
            case 6: disp(); break;
            default: printf("\nInvalid selection! Please try again.\n");
        }
    }
    return 0;
}

// Function to insert element from the Right side
void rinsert()
{
    int value;
    if(rear >= max)
    {
        printf("\nQueue Overflow! Cannot insert at right.\n");
        return;
    }
    
    printf("Enter value to insert at Right: ");
    scanf("%d", &value);
    
    rear = rear + 1;
    queue[rear] = value;
    
    if(front == 0) front = 1; // Set front if first element
}

// Function to delete element from the Left side
void ldelete()
{
    if(front == 0)
    {
        printf("\nQueue Underflow! Nothing to delete from left.\n");
        return;
    }
    
    printf("\nValue %d deleted from Left.", queue[front]);
    queue[front] = 0; // Resetting value for display clarity

    if(rear == front) // Only one element was present
    {
        rear = 0;
        front = 0;
    }
    else
    {
        front = front + 1;
    }
}

// Function to insert element from the Left side
void linsert()
{
    int value;
    if(front <= 1 && rear != 0) // Front is at the beginning and queue is not empty
    {
        printf("\nQueue Overflow! No space at left.\n");
        return;
    }

    printf("Enter value to insert at Left: ");
    scanf("%d", &value);

    if(front == 0) // If queue was empty
    {
        front = 1;
        rear = 1;
    }
    else
    {
        front = front - 1;
    }
    queue[front] = value;
}

// Function to delete element from the Right side
void rdelete()
{
    if(rear == 0)
    {
        printf("\nQueue Underflow! Nothing to delete from right.\n");
        return;
    }

    printf("\nValue %d deleted from Right.", queue[rear]);
    queue[rear] = 0;

    if(front == rear) // Only one element was present
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear - 1;
    }
}

// Function to display current status of the queue
void disp()
{
    int i;
    printf("\nQueue Status: [");
    for(i = 1; i <= max; i++)
    {
        printf(" %d ", queue[i]);
    }
    printf("]\n");
}