#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

struct d_linklist {
    struct d_linklist *prev;
    int info;
    struct d_linklist *next;
} *l = NULL, *r = NULL; // 'l' is HEAD (left), 'r' is TAIL (right)

// Function Prototypes
void f_insert();
void l_insert();
void d_insert();
void f_delete();
void l_delete();
void d_delete();
void display_l();

int main() {
    int choice;

    // We start with an empty list instead of forcing a 'create' loop
    while(1) {
        printf("\n\n=== DOUBLY LINKED LIST MENU ===");
        printf("\n 1. Insert at First");
        printf("\n 2. Insert at Last");
        printf("\n 3. Insert at Any Position");
        printf("\n 4. Delete from First");
        printf("\n 5. Delete from Last");
        printf("\n 6. Delete from Any Position");
        printf("\n 7. Exit");
        printf("\n\n ENTER YOUR CHOICE ===> ");
        
        if (scanf("%d", &choice) != 1) {
            printf("\n Invalid input!\n");
            break;
        }

        switch(choice) {
            case 1: f_insert(); display_l(); break;
            case 2: l_insert(); display_l(); break;
            case 3: d_insert(); display_l(); break;
            case 4: f_delete(); display_l(); break;
            case 5: l_delete(); display_l(); break;
            case 6: d_delete(); display_l(); break;
            case 7: exit(0);
            default: printf("\n Invalid Choice! Try again.\n");
        }
    }
    return 0;
}

// 1. Insert at First
void f_insert() {
    struct d_linklist *new_node = (struct d_linklist *)malloc(sizeof(struct d_linklist));
    printf(" Enter element to insert at first: ");
    scanf("%d", &new_node->info);
    new_node->prev = NULL;
    new_node->next = l;

    if (l == NULL) { // If list was empty
        r = new_node;
    } else {
        l->prev = new_node;
    }
    l = new_node; // Update head pointer
}

// 2. Insert at Last
void l_insert() {
    struct d_linklist *new_node = (struct d_linklist *)malloc(sizeof(struct d_linklist));
    printf(" Enter element to insert at last: ");
    scanf("%d", &new_node->info);
    new_node->next = NULL;
    new_node->prev = r;

    if (r == NULL) { // If list was empty
        l = new_node;
    } else {
        r->next = new_node;
    }
    r = new_node; // Update tail pointer
}

// 3. Insert at Any Position
void d_insert() {
    int pos, i = 1;
    struct d_linklist *new_node, *temp = l;

    printf(" Enter Position to insert element: ");
    scanf("%d", &pos);

    if (pos == 1) {
        f_insert();
        return;
    }

    // Traverse to the node JUST BEFORE the target position
    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\n [ERROR] Position out of bounds!\n");
        return;
    }

    new_node = (struct d_linklist *)malloc(sizeof(struct d_linklist));
    printf(" Enter element: ");
    scanf("%d", &new_node->info);

    // Careful pointer rewiring!
    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = new_node; // Connect right side back to new node
    } else {
        r = new_node; // If inserted at the very end, update tail
    }
    temp->next = new_node; // Connect left side to new node
}

// 4. Delete from First
void f_delete() {
    if (l == NULL) {
        printf("\n [ERROR] List is already empty!\n");
        return;
    }
    struct d_linklist *temp = l;
    l = l->next; // Move head to next node

    if (l != NULL) {
        l->prev = NULL;
    } else {
        r = NULL; // List became empty
    }
    printf("\n [-] Deleted %d from the list.\n", temp->info);
    free(temp); // Free memory to prevent memory leaks!
}

// 5. Delete from Last
void l_delete() {
    if (r == NULL) {
        printf("\n [ERROR] List is already empty!\n");
        return;
    }
    struct d_linklist *temp = r;
    r = r->prev; // Move tail to previous node

    if (r != NULL) {
        r->next = NULL;
    } else {
        l = NULL; // List became empty
    }
    printf("\n [-] Deleted %d from the list.\n", temp->info);
    free(temp); 
}

// 6. Delete from Any Position
void d_delete() {
    if (l == NULL) {
        printf("\n [ERROR] List is empty!\n");
        return;
    }

    int pos, i = 1;
    struct d_linklist *temp = l;

    printf(" Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        f_delete();
        return;
    }

    // Traverse to the exact node to delete
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("\n [ERROR] Position out of bounds!\n");
        return;
    }

    // Bypass the node being deleted
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    } else {
        r = temp->prev; // If deleting the last node, update tail
    }

    printf("\n [-] Deleted %d from position %d.\n", temp->info, pos);
    free(temp);
}

// Visual Display Function
void display_l() {
    struct d_linklist *ptr = l;
    printf("\n CURRENT LIST ===>\n\n");
    
    if (ptr == NULL) {
        printf("    [ EMPTY ]\n");
        return;
    }

    printf(" NULL <== ");
    while (ptr != NULL) {
        printf("[%d]", ptr->info);
        if (ptr->next != NULL) {
            printf(" <==> ");
        }
        ptr = ptr->next;
    }
    printf(" ==> NULL\n");
    printf("--------------------------------------------------\n");
}