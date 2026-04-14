#include<stdio.h>
#include<conio.h>

// Function prototype for Binary Search
void b_search(int[] , int , int );

int main() // Changed to int main for standard compliance
{
   int x[101]; // Increased size slightly to safely handle 1-based indexing up to 100
   int i, no, d, temp, j;

//    clrscr(); // Clears the console screen (Turbo C specific)

   printf("Enter how many elements to insert: ");
   scanf("%d", &no);

   // Input Loop: Storing elements starting from index 1
   for(i = 1; i <= no; i++)
   {
       printf("Enter element %d: ", i);
       scanf("%d", &x[i]);
   }

   // Sorting Logic: Sorting the array in ascending order (Required for Binary Search)
   for(i = 1; i <= no; i++)
   {
       for(j = 1; j <= no; j++)
       {
         if(x[i] < x[j])
         {
            temp = x[i];
            x[i] = x[j];
            x[j] = temp;
         }
       }
   }

   // Displaying the sorted array
   printf("\nAfter Ascending Order: ");
   for(i = 1; i <= no; i++)
   {
       printf(" %d", x[i]);
   }

   // Asking user for the target value
   printf("\nWhich Number Do you Search: ");
   scanf("%d", &d);

   // Calling the binary search function
   b_search(x, no, d);

   getch(); // Holds the output screen
   return 0; // Return statement for int main
}

// Binary Search Function Definition
void b_search(int x[101], int no, int d)
{
      int low = 1;      // Starting index
      int high = no;    // Ending index
      int mid;

      // Loop continues until the search range is exhausted
      while(low <= high)
      {
            mid = (low + high) / 2; // Find the middle element

            if(d < x[mid]) 
            {
                // Target is in the left half
                high = mid - 1;
            }
            else if(d > x[mid])
            {
                // Target is in the right half
                low = mid + 1;
            }
            else if(d == x[mid])
            {
                // Target found
                printf("Number found!");
                return;
            }
      }

      // If loop ends without returning, number was not in the list
      printf("Number search Unsuccessful!");
}