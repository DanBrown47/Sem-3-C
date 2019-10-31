#include <stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
void main()
{
	
	int i;
	int num ;
	struct  node *first, *nw, *pre, *new1, *count;

	printf("\n Enter the number of node you want to create: ");
	scanf("%d", &num );
	first->next = NULL;
	nw = first; 
	for (i=0;i<num;i++)
	{
		nw->next = (struct node*)malloc(sizeof(struct node));
		nw = nw->next;
		printf("\n Enter the node %d: ", i+1);
		scanf("%d", &nw->data);
		nw->next = NULL;
	}
	new1 = first;
	for( ; new1->next != NULL; new1 = new1->next)
	{
		for(count = new1->next; count != NULL; count = count->next)
		{
			if(new1->data > count->data)
			{
				int temp = new1->data;
				new1->data = count->data;
				count->data = temp;
			}
		}
	}
	nw = first->next;
	printf("\n After sorting the Linked list is as follows:\n");
	while (nw)
	{
		printf("%d\t", nw->data);
		nw = nw->next;
	}
	
}
