
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// INSERT AT BEGINNING
void insertBegin() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
    printf("Inserted successfully.\n");
}

// INSERT AT END
void insertEnd() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    } else {
        temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
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
    for (i = 1; i < pos - 1 && temp->next != head; i++)
        temp = temp->next;

    if (i != pos - 1) {
        printf("Invalid position.\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    temp->next = newnode;

    printf("Inserted successfully.\n");
}

// DELETE AT BEGINNING
void deleteBegin() {
    struct node *temp, *last;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        last = head;
        while (last->next != head)
            last = last->next;

        head = head->next;
        last->next = head;
        free(temp);
    }

    printf("Deleted from beginning.\n");
}

// DELETE AT END
void deleteEnd() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = head;
        free(temp);
    }

    printf("Deleted from end.\n");
}

// DELETE AT MIDDLE / GIVEN POSITION (1-BASED)
void deleteMiddle() {
    struct node *temp, *prev;
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
    for (i = 1; i < pos && temp->next != head; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (i != pos) {
        printf("Invalid position.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);

    printf("Deleted from position %d.\n", pos);
}

// DISPLAY LIST
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    temp = head;
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(back to head)\n");
}

// MAIN MENU
int main() {
    int choice;

    do {
        printf("\n--- CIRCULAR LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Middle (by position)\n");
        printf("3. Insert at End\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at Middle (by position)\n");
        printf("6. Delete at End\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBegin(); break;
            case 2: insertMiddle(); break;
            case 3: insertEnd(); break;
            case 4: deleteBegin(); break;
            case 5: deleteMiddle(); break;
            case 6: deleteEnd(); break;
            case 7: display(); break;
            case 8: printf("Exiting program.\n"); break;
            default: printf("Invalid choice.\n");
        }

    } while (choice != 8);

    return 0;
}