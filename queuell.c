#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	int *next;
};	
struct node *head=NULL,*pos=NULL,*tail=NULL;
int size=0;
int isempty()
{
	if(tail==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void enqueue(int val)
{
	if(tail==NULL)
	{
		head=(struct node*)malloc(sizeof(struct node));
		head->data=val;
		pos=head;
		tail=head;
		size++;
	}
	else 
	{
		tail->next=(struct node*)malloc(sizeof(struct node));
		tail=tail->next;
		tail->data=val;
		size++;
	}
	
}
void dequeue()
{
	int num;
	if(head==NULL)
	{
		printf("\nUnderflow");
	}
	else
	{
		num=pos->data;
		head=head->next;
		pos->next=NULL;
		free(pos);
		pos=head;
		size--;
		printf("\n%dDequeued",num);
	}
}
void display()
{
	pos=head;
	printf("\nSize of Queue is%d",size);
	printf("\nElements are :");
	while(pos!=NULL)
	{
		printf("\t%d",pos->data);
		pos=pos->next;
	}
	pos=head;
	
}
void main()
{
	int ch,entry;
	while(1)
	{
			printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
				{
					printf("\nEnter Value to Insert :");
					scanf("%d",&entry);
					enqueue(entry);
					break;
				}
				case 2:
				{
					dequeue();
					break;
				}
				case 3:
				{
					display();
					break;
				}
				case 4:
				{
					printf("Exit..");
					exit(0);
				}
				default:
				{
					printf("\nInvalid choice\n");
				}
			}
		
	}
}
