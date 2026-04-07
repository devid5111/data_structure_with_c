#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1; // Stack starts empty

void push();
void pop();
void peep();
void change();
void stack_length(); // New function added
void disp();

int main() {
    int choice;

    while(1) {
        printf("\n\n=== STACK MENU ===");
        printf("\n 1. Push");
        printf("\n 2. Pop");
        printf("\n 3. Peep");
        printf("\n 4. Change");
        printf("\n 5. Stack Length"); // New menu option
        printf("\n 6. Exit");
        printf("\n\n Enter your choice ===> ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n Invalid input!");
            break; 
        }

        switch(choice) {
            case 1: push(); disp(); break;
            case 2: pop();  disp(); break;
            case 3: peep(); disp(); break;
            case 4: change(); disp(); break;
            case 5: stack_length(); disp(); break; // Added to switch case
            case 6: exit(0);
            default: printf("\n Invalid choice! Please enter 1-6.\n");
        }
    }
    return 0;
}

void push() {
    int x;
    if (top >= MAX - 1) {
        printf("\n [ERROR] STACK OVERFLOW! Cannot push.\n");
        return;
    }

    printf(" Enter value to push ==> ");
    scanf("%d", &x);

    top = top + 1;
    stack[top] = x;
    printf("\n [+] Successfully pushed %d into the stack.\n", x);
}

void pop() {
    if (top == -1) {
        printf("\n [ERROR] STACK UNDERFLOW! Stack is empty.\n");
        return;
    }

    int x = stack[top];
    stack[top] = 0; 
    top = top - 1;

    printf("\n [-] Successfully popped %d from the stack.\n", x);
}

void peep() {
    int i;
    printf(" Enter position to peep (1 to %d from top) ==> ", top + 1);
    scanf("%d", &i);

    if (top - i + 1 < 0 || i <= 0) {
        printf("\n [ERROR] INVALID POSITION!\n");
        return;
    }
    
    printf("\n [*] Element at position %d from top is %d\n", i, stack[top - i + 1]);
}

void change() {
    int i, x;
    printf(" Enter position to change (1 to %d from top) ==> ", top + 1);
    scanf("%d", &i);

    if (top - i + 1 < 0 || i <= 0) {
        printf("\n [ERROR] INVALID POSITION!\n");
        return;
    }

    printf(" Enter new element ==> ");
    scanf("%d", &x);

    stack[top - i + 1] = x;
    printf("\n [~] Value changed successfully.\n");
}

// === NEW FUNCTION ===
void stack_length() {
    int length = top + 1;
    printf("\n [i] The current length of the stack is: %d\n", length);
    
    if (length == MAX) {
        printf("     (The stack is currently FULL)\n");
    } else if (length == 0) {
        printf("     (The stack is currently EMPTY)\n");
    }
}

void disp() {
    int i;
    printf("\n-------------------------");
    printf("\n CURRENT STACK STATUS: \n");

    if (top == -1) {
        printf("\n\t [ EMPTY ]\n");
    } else {
        for(i = top; i >= 0; i--) {
            printf("\t|  %4d  |", stack[i]);
            if (i == top) {
                printf(" <== TOP");
            }
            printf("\n");
        }
        printf("\t|________|\n");
    }
    printf("-------------------------\n");
}