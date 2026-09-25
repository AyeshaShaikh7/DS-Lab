#include <stdio.h>
#include <limits.h> // For INT_MIN

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull()
{
    return (rear + 1) % MAX_SIZE == front;
}

int isEmpty()
{
    return front == -1;
}

void enqueue(int data)
{
    if (isFull())
    {
        printf("Queue Overflow: Cannot insert %d\n", data);
        return;
    }
    if (front == -1)
        front = 0; // First element

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = data;
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow: Nothing to delete\n");
        return INT_MIN;
    }
    int data = queue[front];
    if (front == rear)
    {
        front = rear = -1; // Reset queue
    }
    else
    {
        front = (front + 1) % MAX_SIZE;
    }
    return data;
}

int peek()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return queue[front];
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[rear]);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Queue elements : ");
    display();

    printf("Front element (peek): %d\n", peek());
    printf("Dequeued element: %d\n", dequeue());

    printf("Queue elements : ");
    display();

    return 0;
}