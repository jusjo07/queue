#include <stdio.h>
#include <stdlib.h>
#define n 5
int rear=-1;
int front=-1;
int queue[n];
int isfull()
{	
	if (rear==n-1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isempty()
{
	if(front==-1)
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
	if(isfull())
	{
		printf("\nQueue Full");
	}
	else 
	{
		if(front==-1)
		{
			front =0;
		}
		rear++;
		queue[rear]=val;
		printf("\n%d Enqueued",queue[rear]);
	}

}
void dequeue()
{
	if(isempty())
	{
		printf("Queue empty");
	}
	else
	{
		printf("\n Dequeued",queue[front]);
		front++;
	}
	if (front>rear)
	{
		front=-1;
		rear=-1;
	}
}
void display()
{
	int i,x;
	x=front;
	for(i=x;i<=rear;i++)
	{
		printf("\n%d",queue[i]);
	}
}
void main()
{
	int ch,entry;
	while(1)
	{
		int c,entry;
		while(1)
		{
			printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Empty or Full\n5.Exit\nEnter your choice");
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
					if(isfull())
					{
						printf("\nStack is full");
					}
					else if(isempty())
					{
						printf("\nStack is empty");
					}
					else
					{
						printf("\nStack is neither full nor empty");
					}
					break;
				}
				case 5:
				{
					printf("Exit...");
					exit(0);
				}
				default:
				{
					printf("Invalid choice");
				}
			}
		}

	}
}
