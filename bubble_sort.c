#include <stdio.h>

void sort(int[], int);

int main() // main() hamesha 'int' return kare te badhu saru
{
    int x[50], no;
    int i;

    printf("How many elements do you want :: ");
    scanf("%d", &no);

    // Loop 0 thi start karo
    for (i = 0; i < no; i++)
    {
        printf("Enter element [%d] : ", i + 1);
        scanf("%d", &x[i]);
    }

    sort(x, no);
    
    return 0;
}

void sort(int k[], int no)
{
    int pass, i, temp, ex;
    int last = no - 1; // Last index 'no-1' hoy

    for (pass = 0; pass < no - 1; pass++)
    {
        ex = 0;

        for (i = 0; i < last; i++) // 0 thi last-1 sudhi loop
        {
            if (k[i] > k[i + 1])
            {
                temp = k[i];
                k[i] = k[i + 1];
                k[i + 1] = temp;
                ex++;
            }
        }

        if (ex == 0)
        {
            printf("\nArray was already sorted or sorting finished early.\n");
            break;
        }
        
        last--; // Dar vakhte chello element sorted thai jay, etle loop nani karo
    }

    printf("\nSorted Array:\n");
    for (i = 0; i < no; i++)
    {
        printf("%d ", k[i]);
    }
}