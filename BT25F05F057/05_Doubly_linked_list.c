
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// INSERT AT BEGINNING
void insertBegin() {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;

    printf("Inserted successfully.\n");
}

// INSERT AT END
void insertEnd() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
    } else {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }

    printf("Inserted successfully.\n");
}

// INSERT AT MIDDLE / GIVEN POSITION (1-BASED)
void insertMiddle() {
    struct node *newnode, *temp;
    int pos, i;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        insertBegin();
        return;
    }

    if (head == NULL) {
        printf("Invalid position.\n");
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (i != pos - 1) {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;

    printf("Inserted successfully.\n");
}

// DELETE AT BEGINNING
void deleteBegin() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);

    printf("Deleted from beginning.\n");
}

// DELETE AT END
void deleteEnd() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (head->next == NULL) {
        head = NULL;
    } else {
        while (temp->next != NULL)
            temp = temp->next;

        temp->prev->next = NULL;
    }

    free(temp);

    printf("Deleted from end.\n");
}

// DELETE AT MIDDLE / GIVEN POSITION (1-BASED)
void deleteMiddle() {
    struct node *temp;
    int pos, i;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    if (pos == 1) {
        deleteBegin();
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);

    printf("Deleted from position %d.\n", pos);
}

// DISPLAY FORWARD
void displayForward() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    printf("Forward: NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

// DISPLAY REVERSE
void displayReverse() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    printf("Reverse: NULL <-> ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}

// MAIN MENU
int main() {
    int choice;

    do {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle (by position)\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Middle (by position)\n");
        printf("6. Delete at End\n");
        printf("7. Display Forward\n");
        printf("8. Display Reverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBegin(); break;
            case 2: insertMiddle(); break;
            case 3: insertEnd(); break;
            case 4: deleteBegin(); break;
            case 5: deleteMiddle(); break;
            case 6: deleteEnd(); break;
            case 7: displayForward(); break;
            case 8: displayReverse(); break;
            case 9: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 9);

    return 0;
}