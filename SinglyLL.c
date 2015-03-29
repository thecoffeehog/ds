#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
//Defining a node
typedef struct
{
    int data;
    struct node *next;
}node;
//Defining pointer variables of type node
node *start = NULL,*temp,*q;

void create();
void insert();
void delete();
void display();
void insert_beg();
void insert_end();
void insert_mid();
void delete_beg();
void delete_end();
void delete_mid();
int main()
{
    int choice;
    do
    {
    printf("\t\tMenu\t\t\n");
    printf("Enter 1 to Create the linked list\n");
    printf("Enter 2 to Insert element at beginning in the linked list\n");
    printf("Enter 3 to Insert element at middle in the linked list\n");
    printf("Enter 4 to Insert element at end in the linked list\n");
    printf("Enter 5 to Delete element from the beginning of linked list\n");
    printf("Enter 6 to Delete element from the middleof linked list\n");
    printf("Enter 7 to Delete element from the end of linked list\n");
    printf("Enter 8 to Display the linked list\n");
    printf("Enter 9 to Exit\n");
    printf("Your choice: ");
    scanf("%d",&choice);
    printf("\n");
    
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
            case 5: delete_beg();
                    break;
            case 6: delete_mid();
                    break;
            case 7: delete_end();
                    break;
        	case 8: display();
                    break;
		    case 9: exit(0);
                    break;
            default: printf("Wrong Choice");
        }
    }while(choice != 50);

    return 0;

}
void create()//Creates a linked list with one element
{
    if(start==NULL)
        {
            temp=(node*)malloc(sizeof(node));//Creates a single node
            printf("Enter data: ");
            scanf("%d",&temp->data);
            temp->next=NULL;
            start=temp;
            printf("Created Sucessfully");
        }
}
void display()
{
    q=start;
    printf("The elements present in the linked list are: \n");
    while(q->next!=NULL)//Travels till the end of the list
    {
        printf("%d\n",q->data);
		q=q->next;
    }
}
void insert_beg()
    {
        if(start==NULL)
        {
            create();
        }
        else
        {
            temp=(node*)malloc(sizeof(node));//Creates an empty node and allocates some memory to it           
            printf("Enter data: ");
            scanf("%d",&temp->data);
        	temp -> next = NULL;
           	temp->next=start;//Attach temp to start
            start=temp; 
        }
    }
void insert_mid()
    {
        if(start!=NULL)
        {
            temp=(node*)malloc(sizeof(node));
            printf("Enter data: ");
            scanf("%d",&temp->data);
            temp -> next = NULL;
            int num;
            printf("Enter the data after which you want to insert the new data");
            scanf("%d",&num);
            q = start;
    	    while(q -> data!=num)
    	    q = q -> next;
            temp -> next = q -> next;
    	    q -> next = temp;
         }
    }
void insert_end()
    {
        if(start!=NULL)
        {
            temp=(node*)malloc(sizeof(node));           
            printf("Enter data: ");
            scanf("%d",&temp->data);
           temp -> next = NULL;
    	    q = start;
    	    while(q -> next != NULL)
    	    q = q -> next;
    	    q -> next = temp;

        }
    }
void delete_beg()
    {
       int num;
       if(start!=NULL)
        {
            q=start;
            printf("Enter the no. to be deleted: \n");
            scanf("%d",&num);
            if(q->data==num)
            {
                start=start->next;
                q->next=NULL;
                free(q);
                printf("The no. %d is deleted\n",num);
            }
            else
            {
                printf("The no. is not present at the start");
            }
        }    
    }
void delete_end()
    {
       int num;
       node *r;
       if(start!=NULL)
        {
            int flag=0;
            q=start;
            printf("Enter the no. to be deleted: \n");
            scanf("%d",&num);
            while(flag==0)
            {
                if(q->data==num)
                    flag=1;
                else
                    q=q->next;
            }
            if(flag==1)
            r=start;
                while(r->next!=q)
                {
                    r=r->next;
                }
                r->next=NULL;
                q->next=NULL;
                free(q);
                printf("No %d is now deleted from the Linked List",num);
            }
    }
void delete_mid()
    {
      int num;
       node *r;
       if(start!=NULL)
        {
            int flag=0;
            q=start;
            printf("Enter the no. to be deleted: \n");
            scanf("%d",&num);
            while(flag==1 && q!=NULL)
            {
                {
                    if(q->data==num)
                       {
                        flag=1;
                       }
                    else
                        q=q->next;
                }
            if(flag==0)
            {
                printf("Data Not Found!");
            }
            else
            r=start;
            while(r->next!=q)
                {
                    r=r->next;
                }
                r->next=q->next;
                q->next=NULL;
                free(q);
                printf("No. %d deleted :) ",num);
            }  
       }
}
