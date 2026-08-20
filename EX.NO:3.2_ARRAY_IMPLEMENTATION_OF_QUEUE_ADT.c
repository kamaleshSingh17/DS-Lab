#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue
{
    int arr[MAX];
    int front;
    int rear;
};

void initializeQueue(struct Queue *queue);
int isFull(struct Queue *queue);
int isEmpty(struct Queue *queue);
void enqueue(struct Queue *queue, int element);
int dequeue(struct Queue *queue);
void displayQueue(struct Queue *queue);

int main()
{
    struct Queue queue;
    int choice, element;

    initializeQueue(&queue);

    while (1)
    {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &element);

                enqueue(&queue, element);
                break;

            case 2:
                element = dequeue(&queue);

                if (element != -1)
                    printf("Dequeued element: %d\n", element);

                break;

            case 3:
                displayQueue(&queue);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}

void initializeQueue(struct Queue *queue)
{
    queue->front = 0;
    queue->rear = -1;
}

int isFull(struct Queue *queue)
{
    return queue->rear == MAX - 1;
}

int isEmpty(struct Queue *queue)
{
    return queue->front > queue->rear;
}

void enqueue(struct Queue *queue, int element)
{
    if (isFull(queue))
    {
        printf("Queue Overflow\n");
        return;
    }

    queue->rear++;
    queue->arr[queue->rear] = element;

    printf("Element enqueued: %d\n", element);
}

int dequeue(struct Queue *queue)
{
    int element;

    if (isEmpty(queue))
    {
        printf("Queue Underflow\n");
        return -1;
    }

    element = queue->arr[queue->front];
    queue->front++;

    return element;
}

void displayQueue(struct Queue *queue)
{
    int i;

    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");

    for (i = queue->front; i <= queue->rear; i++)
        printf("%d ", queue->arr[i]);

    printf("\n");
}

Output

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to enqueue: 10
Element enqueued: 10

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to enqueue: 20
Element enqueued: 20

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 1
Enter element to enqueue: 30
Element enqueued: 30

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 10 20 30

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 2
Dequeued element: 10

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 3
Queue elements: 20 30

Queue Operations Menu:
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter your choice: 4
