#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* next;
};

struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}

void display(struct Node* head) {
struct Node* temp = head;
if (temp == NULL) {
printf("List is empty.\n");
return;
}
while (temp != NULL) {
printf("%d ", temp->data);
temp = temp->next;
}
printf("\n");
}

void push(struct Node** top, int data) {
struct Node* newNode = createNode(data);
newNode->next = *top;
*top = newNode;
printf("Pushed %d onto stack\n", data);
}

void pop(struct Node** top) {
if (*top == NULL) {
printf("Stack is empty\n");
return;
}
struct Node* temp = *top;
*top = (*top)->next;
printf("Popped %d from stack\n", temp->data);
free(temp);
}

void enqueue(struct Node** front, struct Node** rear, int data) {
struct Node* newNode = createNode(data);
if (*rear == NULL) {
*front = *rear = newNode;
printf("Enqueued %d to queue\n", data);
return;
}
(*rear)->next = newNode;
*rear = newNode;
printf("Enqueued %d to queue\n", data);
}

void dequeue(struct Node** front, struct Node** rear) {
if (*front == NULL) {
printf("Queue is empty\n");
return;
}
struct Node* temp = *front;
*front = (*front)->next;
if (*front == NULL) {
*rear = NULL;
}
printf("Dequeued %d from queue\n", temp->data);
free(temp);
}

int main() {
struct Node* stackTop = NULL;
struct Node* queueFront = NULL;
struct Node* queueRear = NULL;
int choice, data;

while (1) {
printf("\nMenu:\n");
printf("1. Stack/Queue Operations\n");
printf("2. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

if (choice == 2) {
break;
}

printf("\nSelect Operation:\n");
printf("1. Push (Stack)\n");
printf("2. Pop (Stack)\n");
printf("3. Enqueue (Queue)\n");
printf("4. Dequeue (Queue)\n");
printf("5. Display Stack/Queue\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1:
printf("Enter data to push: ");
scanf("%d", &data);
push(&stackTop, data);
break;
case 2:
pop(&stackTop);
break;
case 3:
printf("Enter data to enqueue: ");
scanf("%d", &data);
enqueue(&queueFront, &queueRear, data);
break;
case 4:
dequeue(&queueFront, &queueRear);
break;
case 5:
printf("Stack: ");
display(stackTop);
printf("Queue: ");
display(queueFront);
break;
default:
printf("Invalid choice\n");
}
}

return 0;
}
