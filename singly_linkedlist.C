#include<stdio.h>
#include<conio.h>
#include<stdlib.h> // Essential for malloc and free

struct linklist {
    int info;
    struct linklist *next;
};

struct linklist *start = NULL;

void create();
void display();
void finsert();
void linsert();
void minsert();
void fdelete();
void ldelete();
void mdelete();

int main() {
    int n;
    // clrscr();

    create(); // Create initial list
    display();

    while(1) {
        printf("\n--- MENU ---");
        printf("\n 1 FOR FIRST INSERT");
        printf("\n 2 FOR LAST INSERT");
        printf("\n 3 FOR POSITION INSERT");
        printf("\n 4 FOR FIRST DELETE");
        printf("\n 5 FOR LAST DELETE");
        printf("\n 6 FOR DELETE BY VALUE");
        printf("\n 7 FOR EXIT");
        printf("\n ENTER YOUR CHOICE ==> ");
        scanf("%d", &n);

        switch(n) {
            case 1: finsert(); break;
            case 2: linsert(); break;
            case 3: minsert(); break;
            case 4: fdelete(); break;
            case 5: ldelete(); break;
            case 6: mdelete(); break;
            case 7: exit(0);
            default: printf("\nWrong key pressed!\n");
        }
        display();
    }
}

void create() {
    struct linklist *ptr, *temp;
    char ch;
    
    // Initializing the first node
    start = (struct linklist *)malloc(sizeof(struct linklist));
    printf("Enter value: ");
    scanf("%d", &start->info);
    start->next = NULL;
    ptr = start;

    printf("Continue? (y/n): ");
    fflush(stdin);
    ch = getchar();

    while(ch == 'y' || ch == 'Y') {
        temp = (struct linklist *)malloc(sizeof(struct linklist));
        printf("Enter value: ");
        scanf("%d", &temp->info);
        temp->next = NULL;
        
        ptr->next = temp;
        ptr = temp;

        printf("Continue? (y/n): ");
        fflush(stdin);
        ch = getchar();
    }
}

void display() {
    struct linklist *ptr = start;
    if(ptr == NULL) {
        printf("\nList is empty.\n");
        return;
    }
    printf("\nList: ");
    while(ptr != NULL) {
        printf("%d -> ", ptr->info);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void finsert() {
    struct linklist *new_node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("Enter Value: ");
    scanf("%d", &new_node->info);
    new_node->next = start;
    start = new_node;
}

void linsert() {
    struct linklist *new_node, *ptr = start;
    new_node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("Enter Value: ");
    scanf("%d", &new_node->info);
    new_node->next = NULL;

    if(start == NULL) {
        start = new_node;
        return;
    }
    while(ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = new_node;
}



void minsert() {
    struct linklist *ptr = start, *new_node;
    int pos, i = 1;
    printf("Enter Position: ");
    scanf("%d", &pos);

    new_node = (struct linklist *)malloc(sizeof(struct linklist));
    printf("Enter Value: ");
    scanf("%d", &new_node->info);

    if(pos == 1) {
        new_node->next = start;
        start = new_node;
        return;
    }

    while(i < pos - 1 && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL) {
        printf("Position out of range.\n");
    } else {
        new_node->next = ptr->next;
        ptr->next = new_node;
    }
}

void fdelete() {
    if(start == NULL) return;
    struct linklist *temp = start;
    start = start->next;
    free(temp);
}

void ldelete() {
    if(start == NULL) return;
    if(start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }
    struct linklist *ptr = start;
    while(ptr->next->next != NULL) {
        ptr = ptr->next;
    }
    free(ptr->next);
    ptr->next = NULL;
}



void mdelete() {
    struct linklist *ptr = start, *prev = NULL;
    int val;
    printf("Enter value to delete: ");
    scanf("%d", &val);

    if(start != NULL && start->info == val) {
        struct linklist *temp = start;
        start = start->next;
        free(temp);
        return;
    }

    while(ptr != NULL && ptr->info != val) {
        prev = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL) {
        printf("Value not found.\n");
        return;
    }
    prev->next = ptr->next;
    free(ptr);
}