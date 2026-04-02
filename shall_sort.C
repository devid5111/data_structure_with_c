#include <stdio.h>

void shell_sort(int arr[], int n);

int main() {
    int x[100];
    int no, i;

    printf("Enter number of elements (max 100): ");
    // Added basic input validation
    if (scanf("%d", &no) != 1 || no <= 0 || no > 100) {
        printf("Invalid input.\n");
        return 1; 
    }

    // Modern C uses 0-based indexing for arrays
    for(i = 0; i < no; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &x[i]);
    }

    shell_sort(x, no);

    printf("\nSORTED LIST ===> ");
    for(i = 0; i < no; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");

    return 0;
}

// Standard Shell Sort using Gapped Insertion Sort
void shell_sort(int arr[], int n) {
    int gap, i, j, temp;

    // Start with a large gap, then reduce it by half each time
    for (gap = n / 2; gap > 0; gap /= 2) {
        
        // Perform a gapped insertion sort for this gap size
        for (i = gap; i < n; i++) {
            temp = arr[i];
            
            // Shift earlier gap-sorted elements up until the correct location is found
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            // Place the temporary variable in its correct sorted location
            arr[j] = temp;
        }
    }
}