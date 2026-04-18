// LINEAR QUEUE IMPLEMENTATION //
#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // For exit()

#define max 5

// Function Prototypes
void insert();
void del();
void display();

int queue[max + 1]; // Size max + 1 to support your 1-based indexing logic
int rear = 0, front = 0;

int main() 
{
    int choice;
    clrscr();

    // Loop for continuous menu interaction
    while(1) 
    {
        printf("\n--- Simple Queue Operations ---");
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                insert();
                display();
                break;
            case 2:
                del();
                display();
                break;
            case 3:
                exit(0);
            default:
                printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}

// Function to add an element to the rear of the queue
void insert() 
{
    int value;
    if (rear >= max) 
    {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    rear = rear + 1;
    queue[rear] = value;

    // If it's the first element being inserted, set front to 1
    if (front == 0) 
    {
        front = 1;
    }
}

// Function to remove an element from the front of the queue (FIFO)
void del() 
{
    int value;
    if (front == 0) 
    {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    value = queue[front];
    queue[front] = 0; // Optional: resetting for display clarity
    printf("\nElement %d deleted from queue.\n", value);

    // If front reaches rear, the queue becomes empty again
    if (front == rear) 
    {
        front = 0;
        rear = 0;
    } 
    else 
    {
        front = front + 1;
    }
}

// Function to display the current state of the queue
void display() 
{
    int i;
    printf("Queue contents: [");
    for (i = 1; i <= max; i++) 
    {
        printf(" %d ", queue[i]);
    }
    printf("]\n");
}
