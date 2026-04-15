// LINEAR SEARCH //
#include<stdio.h>
#include<conio.h>

// Function Prototype
void l_search(int[] , int , int );

int main() 
{
   int x[101]; // Array size 101 to safely handle 1-based indexing
   int i, no, d;

   clrscr(); // Clears the output screen

   printf("Enter how many elements you want to insert: ");
   scanf("%d", &no);

   // Input Loop: Storing elements starting from index 1
   for(i = 1; i <= no; i++)
   {
       printf("Enter element %d: ", i);
       scanf("%d", &x[i]);
   }

   printf("\nWhich number do you want to search: ");
   scanf("%d", &d);

   // Calling the Linear Search function
   l_search(x, no, d);

   getch(); // Wait for user input before closing
   return 0; 
}

// Linear Search Function Definition
void l_search(int x[101], int no, int d)
{
    int found = 0; // Flag variable to track if number is found
    int i;

    // Traversing the array sequentially
    for(i = 1; i <= no; i++)
    {
        if(x[i] == d)
        {
            printf("\nNumber %d found at position %d!", d, i);
            found = 1; // Update flag
            break;     // Exit loop immediately after finding the element
        }
    }

    // If flag remains 0, the number is not present in the array
    if(found == 0)
    {
        printf("\nNumber not found! Search unsuccessful.");
    }
}