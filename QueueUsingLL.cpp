//We implement queue with Linked List using insert at end of linked list and deleting from the end of linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *next;
}node;
node *temp;
node *front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void display();

int main()
{
	int choice;
	while(1)
	{
		printf("\n\t\tMenu\t\t\n");
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
		printf("Your Choice: ");
		scanf("%d",&choice);
		printf("\n");
		
		switch(choice)
		{
			case 1: enqueue();
					break;
			case 2: dequeue();
					break;
			case 3: display();
					break;
			case 4: printf("Thanks for using the program!\n\n");
					exit(0);
					break;
			default: printf("Please enter a valid choice!\n\n");
					break;
		}
		
	}
}
node* temp_input()
{
	temp=(node*)malloc(sizeof(node));//Creates a single node
            printf("Enter data: ");
            scanf("%d",&temp->data);
            printf("\n");
            temp->next=NULL;
            return temp;
}
void enqueue()
{
	if(front==NULL && rear==NULL)
	{
			front=rear=temp_input();
            printf("Queue Created Sucessfully!\n");
    }	
	else
	{
		node *temp;
		temp=temp_input();
		rear->next=temp;
		rear=temp;
	}
}
void dequeue()
{
	node *temp=front;
	if(front==NULL)
	{
		printf("Queue is already empty!");
	}
	else if(front==rear)
	{
		front=rear=NULL;
	}
	else
	{
		front=front->next;
		printf("%d deleted from the queue",temp->data);
		free(temp);
	}
}
void display()
{
	if(front==NULL)
	{
		printf("Sorry the Queue is empty!");
	}
	else
	{
		node *temp;
		temp=front;
		printf("The elements in the linked list are: ");
		printf("\nFront--> ");
		while(temp!=NULL)
		{
			printf("%d\n",temp->data);
			temp=temp->next;
		}
	}
}
