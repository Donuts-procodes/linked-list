#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int main()
{
    int choice;
    struct node *head = NULL;
    do
    {
        printf("\n1.create\n2.insert a new\n3.at beginning\n4.at desire position\n5.traverse\n6.delete at front\n7.delete at any position\n8.exit");
        printf("\nchoose: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            if (head == NULL)
            {
                head = (struct node *)malloc(sizeof(struct node));
                printf("\nenter element:");
                scanf("%d", &head->data);
                head->next = NULL;
            }
            else
            {
                printf("\nnode already created\n");
            }
            break;
        }
        case 2:
        {
            if (head == NULL)
            {
                printf("\nno node created, creat a node first\n");
            }
            else
            {
                struct node *ptr = (struct node *)malloc(sizeof(struct node));
                printf("enter element:");
                scanf("%d", &ptr->data);
                ptr->next = NULL;
                struct node *temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = ptr;
            }
            break;
        }
        case 3:
        {
            if (head == NULL)
            {
                printf("\nno node created, creat a node first\n");
            }
            else
            {
                struct node *ptr = (struct node *)malloc(sizeof(struct node));
                printf("enter element");
                scanf("%d", &ptr->data);
                ptr->next = head->next;
                head->next = ptr;
            }
            break;
        }
        case 4:
        {
            if (head == NULL)
            {
                printf("\nno node created, creat a node first\n");
            }
            else
            {
                int count = 1, pos;
                printf("at what postion you want to insert: ");
                scanf("%d", &pos);
                struct node *ptr = (struct node *)malloc(sizeof(struct node));
                printf("enter element: ");
                scanf("%d", &ptr->data);
                struct node *temp = head;
                if (pos == 1)
                {
                    ptr->next = head->next;
                    head->next = ptr;
                }
                else
                {
                    while (count < pos - 1)
                    {
                        temp = temp->next;
                        count++;
                    }
                    ptr->next = temp->next;
                    temp->next = ptr;
                }
            }
            break;
        }
        case 5:
        {
            if (head == NULL)
            {
                printf("\nno node created, creat a node first\n");
            }
            else
            {
                struct node *temp = head;
                while (temp != NULL)
                {
                    printf("%d\n", temp->data);
                    temp = temp->next;
                }
            }
            break;
        }
        case 6:
        {
            if (head == NULL)
            {
                printf("\nNo node created, create a node first\n");
            }
            else
            {
                struct node *temp = head;
                head = head->next;
                free(temp);
            }
            break;
        }
        case 7:
        {
            int pos;
            if (head == NULL)
            {
                printf("\nNo node created, create a node first\n");
            }
            else
            {
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                if (pos == 1)
                {
                    struct node *temp = head;
                    head = head->next;
                    free(temp);
                }
                else
                {
                    int count = 1;
                    struct node *temp = head;
                    while (count < pos - 1 && temp != NULL)
                    {
                        temp = temp->next;
                        count++;
                    }
                    if (temp != NULL && temp->next != NULL)
                    {
                        struct node *deleteNode = temp->next;
                        temp->next = deleteNode->next;
                        free(deleteNode);
                    }
                    else
                    {
                        printf("Position out of bounds\n");
                    }
                }
            }
            break;
        }
        case 8:
        {
            exit(0);
        }
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (choice != 8);
}