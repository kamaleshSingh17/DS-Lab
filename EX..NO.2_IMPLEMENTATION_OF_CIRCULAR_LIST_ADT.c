#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = createNode(new_data);

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        new_node->next = *head_ref;
    }
    else
    {
        struct Node *temp = *head_ref;

        while (temp->next != *head_ref)
            temp = temp->next;

        temp->next = new_node;
        new_node->next = *head_ref;
    }
}

void printList(struct Node *head)
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != head);

    printf("\n");
}

void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp;
    struct Node *prev = NULL;

    if (*head_ref == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = *head_ref;

    if (temp->data == key && temp->next == *head_ref)
    {
        *head_ref = NULL;
        free(temp);
        return;
    }

    if (temp->data == key)
    {
        while (temp->next != *head_ref)
            temp = temp->next;

        temp->next = (*head_ref)->next;

        free(*head_ref);

        *head_ref = temp->next;
    }
    else
    {
        while (temp->next != *head_ref && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->data != key)
        {
            printf("Key not found in the list\n");
            return;
        }

        prev->next = temp->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int data, choice, key;

    do
    {
        printf("\n1. Insert at End\n");
        printf("2. Delete Node\n");
        printf("3. Print List\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);

                insertEnd(&head, data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &key);

                deleteNode(&head, key);
                break;

            case 3:
                printf("Circular Linked List: ");
                printList(head);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    while (choice != 0);

    return 0;
}




Output

1. Insert at End
2. Delete Node
3. Print List
0. Exit
Enter your choice: 1
Enter data to insert: 52

1. Insert at End
2. Delete Node
3. Print List
0. Exit
Enter your choice: 1
Enter data to insert: 56

1. Insert at End
2. Delete Node
3. Print List
0. Exit
Enter your choice: 1
Enter data to insert: 75

1. Insert at End
2. Delete Node
3. Print List
0. Exit
Enter your choice: 1
Enter data to insert: 89

1. Insert at End
2. Delete Node
3. Print List
0. Exit
Enter your choice: 3
Circular Linked List: 52 56 75 89



