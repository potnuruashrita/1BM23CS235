#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertLeft(struct Node** head, int newData, int targetData) {
    struct Node* current = *head;
    while (current != NULL && current->data != targetData) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Target node not found.\n");
        return;
    }

    struct Node* newNode = createNode(newData);
    newNode->next = current;
    newNode->prev = current->prev;
    if (current->prev != NULL) {
        current->prev->next = newNode;
    } else {
        *head = newNode;
    }
    current->prev = newNode;
}

void deleteNode(struct Node** head, int value) {
    struct Node* current = *head;
    while (current != NULL && current->data != value) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Node with value %d not found.\n", value);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("Node with value %d deleted.\n", value);
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, target;

    while (1) {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Create a new node\n");
        printf("2. Insert node to the left of a specific node\n");
        printf("3. Delete node by value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value for the new node: ");
                scanf("%d", &data);
                struct Node* newNode = createNode(data);
                if (head == NULL) {
                    head = newNode;
                } else {
                    struct Node* temp = head;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newNode;
                    newNode->prev = temp;
                }
                printf("Node with value %d created.\n", data);
                break;

            case 2:
                printf("Enter the value of the new node: ");
                scanf("%d", &data);
                printf("Enter the target node's value to insert left of: ");
                scanf("%d", &target);
                insertLeft(&head, data, target);
                break;

            case 3:
                printf("Enter the value to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 4:
                displayList(head);
                break;

            case 5:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}
33