#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;
void createList(int n);
void displayList();
void reverseList();
void main()
{
    int n, data, choice=1;
    head = NULL;
    last = NULL;
    while(choice != 0)
    {
        printf("============================================\n");
        printf("DOUBLY LINKED LIST PROGRAM\n");
        printf("============================================\n");
        printf("1. Create List\n");
        printf("2. Reverse List\n");
        printf("3. Display list\n");
        printf("0. Exit\n");
        printf("--------------------------------------------\n");
        printf("Enter your choice : ");
	scanf("%d", &choice);
	switch(choice)
        {
            case 1:
                printf("Enter the total number of nodes in list: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                reverseList();
                break;
            case 3:
                displayList();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-3");
        }
		printf("\n\n\n\n\n");
    }
}
void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));
	printf("Enter data of 1 node: ");
        scanf("%d", &data);
	head->data = data;
        head->prev = NULL;
        head->next = NULL;
	last = head;
	for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
	    printf("Enter data of %d node: ", i);
            scanf("%d", &data);
	    newNode->data = data;
            newNode->prev = last; 
            newNode->next = NULL;
	    last->next = newNode; 
            last = newNode; 
        }
	printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
void displayList()
{
    struct node * temp;
    int n = 1;
    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");
	while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);
            n++;
            temp = temp->next;
        }
    }
}
void reverseList()
{
    struct node *current, *temp;
    current = head;
    while(current != NULL)
    {        
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;       
        current = temp;
    }       
    temp = head;
    head = last;
    last = temp;
    printf("LIST REVERSED SUCCESSFULLY.\n");
}
