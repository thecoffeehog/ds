#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct node1
{
	struct node1* prev;
	int data;
	struct node1* next;
}node;
node *start=NULL;
node *q;
void delete1();
void create();
void display();
void insert_beg();
void insert_end();
void insert_mid();

int main()
{
	int choice;
	while(1)
	{
		printf("\n\t\tMenu\t\t\n");
		printf("1. Create\n");
		printf("2. Insert at beginning\n");
		printf("3. Insert at middle\n");
		printf("4. Insert at end\n");
		printf("5. Delete\n");
		printf("6. Display\n");
		printf("7. Exit\n");
		printf("Your choice: \n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: create();
					break;
			case 2: insert_beg();
					break;
			case 3: insert_mid();
					break;
			case 4: insert_end();
					break;
     		case 5: delete1();
					break;
			case 6: display();
					break;
			case 7: exit(0);
					break;
			default: printf("Please enter a valid chocie!\n");
					break;
		}
	}
	return 0;	
}
void create()
{
	if(start==NULL)
	{	node* temp;
		temp=(node*)malloc(sizeof(node));
		printf("Enter the first element for the linked list\n");
		scanf("%d",&temp->data);
		temp->prev;
		temp->next=NULL;
		start=temp;
	}
	else
	printf("List already created!\n");
}
void insert_beg()
{
	if(start==NULL)
	{
		create();
	}
	else
	{
		node *temp;
		temp=(node*)malloc(sizeof(node));
		printf("Enter data: \n");
		scanf("%d",&temp->data);
		
		temp->next=start;
		start->prev=temp;
		start=temp;	
	}
}
void insert_mid()
{
	 if(start!=NULL)
	 {
	 	node *temp,*q,*r;
	 	int pos;
		temp=(node*)malloc(sizeof(node));
		printf("Enter data: \n");
		scanf("%d",&temp->data);
		temp->prev=NULL;
		temp->next=NULL;
		printf("Enter the element after which you want to insert the element: \n");
		scanf("%d",&pos);
		q=start;
		r=start;
		while(q->next!=NULL||q->data==pos)
		{
			q=q->next;
		}
		r=q->next;
		q->next=temp;
		temp->prev=q;
		r->prev=temp;
		temp->next=r;
	}
	else
	printf("List is empty!\n");
}
void insert_end()
{
	if(start!=NULL)
	 {
	 	node *temp,*q,*r;
	 	int pos;
	 	q=start;
		temp=(node*)malloc(sizeof(node));
		printf("Enter data: \n");
		scanf("%d",&temp->data);
		temp->prev=NULL;
		temp->next=NULL;
		while(q->next=NULL)
		{
			q=q->next;
		}
		q->next=temp;
		temp->prev=q;
	}
	else
	printf("List is empty\n");
}
//
void delete1()
{   printf("Enter data to delete");
    int data;
    scanf("%d",&data);
    node *r;
	if(start==NULL)
	{
		printf("List is empty!");
	}
	else if(start->next==NULL)//Single Node
	{
		if(start->data=data)
		{
		node *q=start;
		start=NULL;
		free(q);
		}
		else
		printf("Element not found!!");
	}
	else if(start->data==data)//First Node
	{
		node *q;
		q=start;
		start=start->next;
		start->prev=NULL;
		free(q);
	}
	else 
	{   q=start;
        r=start;
        while(q->next!=NULL)
        {
                           
            if(q->data==data)
            { 
                       r->next=q->next;
                       q->next->prev=r;
                       q=NULL;
                       free(q);
                          
            }
            else
            {
                r=q;
                q=q->next;
            }  
            if(q->next==NULL)
            {
                 r->next=NULL;
                 q->prev=NULL;
                 free(q);                        
        }    }             
	}
	
}
//
void display()
{
	q=start;
	while(q!=NULL)
	{
		printf("%d\n",q->data);
		q=q->next;
	}
}

