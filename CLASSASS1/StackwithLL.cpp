#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	node *next;
}node;
node *temp;
//Defining top
node *top=NULL;
void push();
void pop();
void display();

int main()
{
	int choice;
	while(1)
	{
		printf("\n\t\tMenu\t\t\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		printf("Your Choice: ");
		scanf("%d",&choice);
		printf("\n");
		
		switch(choice)
		{
			case 1: push();
					break;
			case 2: pop();
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
void push()
{
	
	if(top==NULL)
	{
			top=temp_input();
            printf("Stack Created Sucessfully!\n");
	}	
	else
	{
			node *temp1;
			temp1=temp_input();
			temp1->next=top;//Attach temp to top
            top=temp1;
	}
}
void pop()
{
	node *s;
	s=top;
	if(s==NULL)
	{
		printf("Stack Empty!");
	}
	else
	{
		top=top->next;
		printf("%d Deleted Sucessfully from Stack!",s->data);
		s->next=NULL;
		free(s);
	}
}
void display()
{
	node *s;
	s=top;
	if(s==NULL)
	{
		printf("Stack Empty!");
	}
	else
	{
		printf("Top-->");
		while(s!=NULL)
		{
			printf("\t%d\n",s->data);
			s=s->next;
		}
	}
}
