#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
typedef struct {
	int data;
	struct node* left;
	struct node* right;
}node;
node *root;
void insert(int);
void find(int,node**,node**);
void display_inorder(node*);
void display(node*,int);
void delete_item(int);
void search(int); 
void case_a(node *, node *);
void case_b(node *, node *);
void case_c(node *, node *);
int main()
{
	int choice,item,itemToDelete,itemToSearch;
	while(1)
	{
	printf("\t\t**Operations on Tree**\t\t\n");
	printf("Enter 1 to Insert\n");
	printf("Enter 2 for Continous Insertion\n");
	printf("Enter 3 to Delete\n");
	printf("Enter 4 to Search\n");
	printf("Enter 5 to Display\n");
	printf("Enter 6 to Exit\n");
	printf("Your Choice: ");
	scanf("%d",&choice);
	printf("\n");
	
		switch(choice)
		{
			case 1: printf("Enter the item to insert: ");
					printf("\n");
					scanf("%d",&item);
					insert(item);
					break;
			case 2: printf("Enter the no of items to insert: ");
					int n;
					scanf("%d",&n);
					printf("\n");
					int i;
					printf("Enter %d items one by one: ",n);
					printf("\n");
					for(i=0;i<n;i++)
					{
					scanf("%d",&item);
					insert(item);
					}
					break;
			case 3: printf("Enter the element to delete: ");
					printf("\n");
					scanf("%d",&itemToDelete);
					delete_item(itemToDelete);
					break;
			case 4: printf("Enter the item to search: ");
					printf("\n");
					scanf("%d",&itemToSearch);
					search(itemToSearch);
					break;
			case 5: display_inorder(root);
					display(root,1);
					break;
			case 6: exit(0);
					break;
			default: printf("Please enter a valid choice!\n");
		}
	}
}

void insert(int item)
{
	node *temp,*parent,*location;
	find(item, &parent, &location);
	if(location!=NULL)
	{
		printf("Item already present!");
		return;
	}
	//Creating an empty node and putting item into it
	temp=(node*)malloc(sizeof(node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	if(parent==NULL)
	{
		root=temp;
	}
	else
	{
	if(item < parent->data)
		parent -> left = temp;
	else
		parent -> right=temp;
	}
}

void find(int item, node **par, node **loc)
{
	node *ptr, *ptrsave;
	if(root==NULL) /*Tree is empty*/
	{
		*loc=NULL;
		*par=NULL;
		return;
	}
	if(item==root->data)/*Item is already at root*/
	{
		*loc=root;
		*par=NULL;
		return;
	}
	if(item<root->data)
		ptr=root->left;/*Item smaller than root and thus its link will point to left*/
	else
		ptr=root->right;/*Item greater than root and thus its link will point to right*/
	ptrsave=root;//Initially the parent is declared as root
	while(ptr!=NULL)
	{
		if(item==ptr->data)//For elements already present in the tree
		{
			*loc=ptr;
			*par=ptrsave;
			return;
		}
		ptrsave=ptr;
		if(item<ptr->data)
			ptr=ptr->left;
		else
			ptr=ptr->right;
	}
	*loc=NULL;//Item Not Found
	*par=ptrsave;
}

void delete_item(int item)
{
	node *parent,*location;
	find(item,&parent,&location);
    if(root == NULL)   /* Tree empty*/
	{
		printf("Tree is already empty");
		return;
	}
	if(location == NULL) /* Item not present in tree*/
	{
		printf("Sorry! Item not present in tree");
		return;
	}
	/*node to be deleted is leaf node*/   
   	if(location->left==NULL && location->right==NULL)
		case_a(parent,location);  

	 /*node to be deleted has only one child*/ 
	if(location->left!=NULL && location->right==NULL)
		case_b(parent,location);
	
	if(location->left==NULL && location->right!=NULL)
		case_b(parent,location);
	
    /*node to be deleted has two children*/
	if(location->left!=NULL && location->right!=NULL)
		case_c(parent,location);
	
	free(location);
}
void case_a(node *par, node *loc )
{
	if(par == NULL) /*item to be deleted is root node*/
		root=NULL;
	else
	{
		if(loc == par -> left)
		     par -> left = NULL;
		else
		     par -> right = NULL;
	}
}
 /*Case in which one child is present*/
void case_b(node *par,node *loc)
{
	node *child;
	/*Initialize child*/
	if(loc -> left != NULL) /*item to be deleted has left */
		child = loc -> left;
	else  /*item to be deleted has right */
		child = loc -> right;
	
	if(par == NULL ) /*Item to be deleted is root node*/
		root = child;
	else
	{
	       if( loc == par -> left) /*item is left of its parent*/
	            par -> left = child;
	       else /*item is right of its parent*/
		par -> right = child;
	}
}
 /*Case in which two children are present*/ 
void case_c(node *par,node *loc)
{
	node *ptr,*ptrsave,*suc,*parsuc;
	/*Find inorder successor and its parent*/
	ptrsave = loc;
	ptr = loc -> right;
	while(ptr -> left != NULL)
	{
		ptrsave = ptr;
		ptr = ptr->left;
	}
	suc=ptr;
	parsuc=ptrsave;
	if(suc -> left == NULL  &&  suc -> right == NULL)
		case_a(parsuc, suc);
	else
		case_b(parsuc, suc);
	if(par == NULL) /*if item to be deleted is root node */
		root = suc;
	else
	{
		if(loc == par -> left)
			par -> left = suc;
		else
		{
			par -> right = suc;
			suc -> left = loc -> left;
			suc -> right = loc -> right;
		}
	}
}
//DBU69
void search(int item)
{
	
	node  *parent,*location;
	find(item,&parent,&location);
	if(root==NULL)
	{
		printf("The tree is empty!\n");
	}
	else if(location==NULL)
	{
		printf("Sorry %d is not present in the tree!\n",item);
	}
	else if(parent==NULL)
	{
		if(root->data==item)
		{
			printf("%d is present at the root\n",item);
		}
	}
	else if(item==location->data)
	{
		if(parent->left!=NULL)
			printf("Item is present in the tree and is the left child of  parent node %d",parent->data);
		else
			printf("Item is present in the tree and is the right child of parent node  %d",parent->data);
	}
	/*else if(item==parent->right->data)
	{
		printf("Item is present in the tree and the parent node of item is %d",parent->data);
	}*/
	else
	{
		printf("Item is not present in the tree");
	}
	
}
void display(node *ptr, int level)

    {

        int i;

        if (ptr != NULL)

        {

            display(ptr->right ,level+1);

            printf("\n");

            if (ptr == root)

             printf("Root->: "); 

            else

            {

                for (i = 0;i < level;i++)

                    printf("       ");

    		}

            printf("%d",ptr->data);

            display(ptr->left, level+1);

        }

    }
void display_inorder(node *r)
{	
	if(r!=NULL) 
	{
	display_inorder(r->left);
	if(r->data==root->data)
		{
			printf("Root->");
			printf("%d\n",r->data);
		}
	else
	printf("      %d\n",r->data);
	display_inorder(r->right);
	}
}
