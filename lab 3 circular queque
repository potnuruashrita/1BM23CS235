#include <stdio.h>
#include <stdlib.h>
#define MAX 5 // Size of the queue
// Function to check if the queue is full
int isFull(int front, int rear) {
return (front == (rear + 1) % MAX);
}
// Function to check if the queue is empty
int isEmpty(int front) {
return front == -1;
}
// Function to insert an element in the queue (enqueue)
void enqueue(int queue[], int *front, int *rear, int value) {
if (isFull(*front, *rear)) {
printf("Queue is full!\n");
} else {
if (*front == -1) // First insertion
*front = 0;
*rear = (*rear + 1) % MAX;
queue[*rear] = value;
printf("Inserted %d\n", value);
}
}

// Function to remove an element from the queue (dequeue)
void dequeue(int queue[], int *front, int *rear) {
if (isEmpty(*front)) {
printf("Queue is empty!\n");
} else {
printf("Deleted %d\n", queue[*front]);
if (*front == *rear) { // Queue has only one element

*front = -1;
*rear = -1;
} else {
*front = (*front + 1) % MAX;
}
}
}
// Function to display the queue
void display(int queue[], int front, int rear) {
if (isEmpty(front)) {
printf("Queue is empty!\n");
} else {
printf("Queue elements are: ");
int i = front;
while (i != rear) {
printf("%d ", queue[i]);
i = (i + 1) % MAX;
}
printf("%d\n", queue[i]); // Display last element
}
}
// Main function to drive the menu using switch-case
int main() {
int queue[MAX];
int front = -1, rear = -1;
int choice, value;

while (1) {
printf("\nCircular Queue Menu:\n");
printf("1. Enqueue\n");
printf("2. Dequeue\n");

printf("3. Display\n");
printf("4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);

switch (choice) {
case 1: // Enqueue
printf("Enter value to insert: ");
scanf("%d", &value);
enqueue(queue, &front, &rear, value);
break;

case 2: // Dequeue
dequeue(queue, &front, &rear);
break;

case 3: // Display
display(queue, front, rear);
break;

case 4: // Exit
printf("Exiting...\n");
exit(0);
break;

default:
printf("Invalid choice! Please try again.\n");
}
}
return 0;
}
