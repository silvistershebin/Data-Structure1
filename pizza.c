#include<stdio.h>
int MAXSIZE = 3;
int rear=0, front=0, earnings=0;
typedef struct{
	char name[20];
	int id;
	int cost;
}order;
int isEmpty()
{
	if(front == rear)
	{
		return 1;
	}
	else 
		return 0;
}
int isFull()
{
	if((rear + 1) % MAXSIZE == front)
		return 1;
	else
		return 0;
}
void enqueue(order queue[MAXSIZE], order item)
{
	queue[rear] = item;
	rear++;
}
void dequeue(order queue[MAXSIZE])
{
	order item = queue[front];
	earnings = earnings + item.cost;
	printf("Order Id\tPizza ordered\t\tRate\n");
	printf("%d\t\t%s\t\t\t%d\n",item.id,item.name,item.cost);
	front++;
}
void display(order queue[MAXSIZE])
{
	if(!isEmpty())
	{
		int i;
		printf("The orders yet to be dispatched are: \n");
		printf("Order Id\tPizza ordered\t\tRate\n");
		for(i=front; i<rear; i++)
		{
			printf("%d\t\t%s\t\t\t%d\n",queue[i].id,queue[i].name,queue[i].cost);
		}		
	}
	else
		printf("\nAll the orders have been delivered. No new orders\n");
}
int main()
{
	order queue[MAXSIZE];
	int c,id=0,name,cost;
	order item;
	printf("\n*********<<<<<< PIZZA MANIA >>>>>>*********");
	do
	{
	printf("\nMENU\n1.Order a pizza\n2.Dispatch order\n3.Display orders\n4.Exit\nEnter your choice... ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
		if(!isFull())
		{
			printf("Enter the name of the pizza ");
			scanf("%s",item.name);
			printf("Enter the cost of the pizza ");
			scanf("%d",&item.cost);
			id++;
			item.id = id;
			enqueue(queue, item);
		}
		else
			printf("\nCan't accept further orders. Deliver some orders first.\n ");
		break;
		case 2:
		if(!isEmpty())
		{
			printf("Order Delivered!. Order summary: ");
			dequeue(queue);
		}
		else
			printf("There are no more orders! ");
		break;
		case 3:
			display(queue);
		case 4:
			break;
		break;
		
		default:printf("\nWrong choice ");
	}
	}while(c!=4);
	printf("Today's Summary: \n");
	printf("Total orders accepted: %d\tEarnings:%d,id,earnings")
	return 0;
}
