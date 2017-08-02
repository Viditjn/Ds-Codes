#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	int height;
	int lc;
	int rc;
	struct node* left;
	struct node* right;
}node;

int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int max(node* a,node* b)
{
	if(a!=NULL && b!=NULL)
		return (a->height)>(b->height)?a->height:b->height;
	if(a!=NULL)
		return a->height;
	if(b!=NULL)
		return b->height;
	else
		return 0;
}

node* srl(node** head)
{
	node *u,*v,*v1;
	v=(*head)->left;
	v1=v->right;
	u=(*head);
	int r1=u->rc,r2=v->rc,r3=v->lc;
	v->right=u;
	u->left=v1;
	u->lc-=r3+1;
	v->rc=r2+r1+1;
	u->height=max(u->left,u->right)+1;
	v->height=max(v->left,v->right)+1;
	//printf("srl\n");
	return v;
}

node* srr(node** head)
{
	node *u,*v,*v1;
	v=(*head)->right;
	v1=v->left;
	u=(*head);
	int l1=u->lc,l2=v->lc;
	v->left=u;
	u->right=v1;
	u->rc=l2;
	v->lc=l1+l2+1;
	u->height=max(u->left,u->right)+1;
	v->height=max(v->left,v->right)+1;
	//printf("srr\n");
	return v;
}

node* drl(node** head)
{
	(*head)->left=srr(&((*head)->left));
	//printf("drl\n");
	return srl(head);
}
node* drr(node** head)
{
	(*head)->right=srl(&((*head)->right));
	//printf("drr\n");
	return srr(head);
}

void insert (node** head,int dat)
{
	if(*head==NULL)
	{
		node* temp;
		temp=(node*)malloc(sizeof(node));
		temp->data=dat;
		temp->height=1;
		temp->lc=0;
		temp->rc=0;
		temp->left=NULL;
		temp->right=NULL;
		*head=temp;
		return;
	}
	else
	{
		if(dat>=(*head)->data)
		{
			(*head)->rc+=1;
			//printf("hi\n");
			insert(&((*head)->right),dat);
		}
		else
		{
			(*head)->lc+=1;
			insert(&((*head)->left),dat);
		}
		(*head)->height=(max((*head)->left,(*head)->right))+1;
		if(height((*head)->left)-height((*head)->right)>1)
		{
			if(height(((*head)->left)->left)>=height(((*head)->left)->right))
				*head=srl(head);
			else
				*head=drl(head);
		}
		else if(height((*head)->right)-height((*head)->left)>1)
		{
			if(height(((*head)->right)->right)>=height(((*head)->right)->left))
				*head=srr(head);
			else
				*head=drr(head);
		}
	}
	return;
}

void print(node** head)
{
	if(*head==NULL)
		return;
	print(&((*head)->left));
	printf("%d,%d,%d,%d; ",(*head)->data,(*head)->height,(*head)->lc,(*head)->rc);
	print(&((*head)->right));
	return;
}

int search(node** head,int dat)
{
	if(*head==NULL)
	{
		//printf("%d not found\n",dat);
		return 0;
	}
	if((*head)->data==dat)
	{
		//printf("%d found\n",dat);
		return 1;
	}
	else
	{
		if(dat>=(*head)->data)
			search(&((*head)->right),dat);
		else
			search(&((*head)->left),dat);
	}
}

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
    return current;
}

void deleteNode(node** head, int data)
{
    // STEP 1: PERFORM STANDARD BST DELETE
    if (*head == NULL)
        return;
    // If the data to be deleted is smaller than the *head's data,
    // then it lies in left subtree
    if ( data < (*head)->data )
	{
		(*head)->lc--;
        deleteNode(&(*head)->left, data);
	}
    // If the data to be deleted is greater than the *head's data,
    // then it lies in right subtree
    else if( data > (*head)->data )
	{
		(*head)->rc--;
        deleteNode(&(*head)->right, data);
	}
    // if data is same as *head's data, then This is the node
    // to be deleted
	else
	{
        // node with only one child or no child
        if( ((*head)->left == NULL) || ((*head)->right == NULL) )
        {
            struct node *temp = (*head)->left ? (*head)->left : (*head)->right;
            // No child case
            if(temp == NULL)
            {
                temp = *head;
                *head = NULL;
            }
            else // One child case
             *head = temp; // Copy the contents of the non-empty child
            //free(temp);
        }
        else
        {
            // node with two children: Get the inorder successor (smallest
            // in the right subtree)
            struct node* temp = minValueNode((*head)->right);
            // Copy the inorder successor's data to this node
            (*head)->data = temp->data;
            // Delete the inorder successor
            deleteNode(&(*head)->right, (*head)->data);
        }
    }
    // If the tree had only one node then return
    if (*head == NULL)
      return;
	(*head)->height=(max((*head)->left,(*head)->right))+1;
  	if(height((*head)->left)-height((*head)->right)>1)
  	{
  		if(height(((*head)->left)->left)>=height(((*head)->left)->right))
  			*head=srl(head);
  		else
  			*head=drl(head);
  	}
  	else if(height((*head)->right)-height((*head)->left)>1)
  	{
  		if(height(((*head)->right)->right)>=height(((*head)->right)->left))
  			*head=srr(head);
  		else
  			*head=drr(head);
  	}
    return ;
}

int kamin(node* head,int dat)
{
	if(head!=NULL){
	if(head->lc == dat-1){
		//printf("Entered on equal %d\n",head->data);
		return head->data;
	}
	if(head->lc > dat-1)
	{
		//printf("Entered Left\n");
		return kamin(head->left,dat);
	}
	else if(head->lc < dat-1)
	{	//printf("Entered Right\n");
		return kamin(head->right,dat-(head->lc)-1);
	}
	}
	//return 0;
}

int top=0;
int co(node* head,int dat)
{
	if(head!=NULL){
	if(head->data<dat)
	{
		//printf("Entered right @ %d lc : %d\n",head->data,head->lc);
		top+=(head->lc)+1;
		return co(head->right,dat);
	}
	else
	{
		//printf("Entered left @ %d lc : %d\n",head->data,head->lc);
		return co(head->left,dat);
	}
	return 0;
}
	//else
}

int main()
{
	int Q,i,num=0;
	node* head=NULL;
	scanf("%d",&Q);
		for(i=0;i<Q;i++)
		{
			int x;
			char a[10];
			scanf("%s %d",a,&x);
			if(a[0]=='I')
			{
				int y=search(&head,x);
				if(y==0)
				{
					num++;
					insert(&head,x);
				}
			}
			if(a[0]=='D')
			{
				int y=search(&head,x);
				if(y==1)
				{
					num--;
					deleteNode(&head,x);
					//print(&head);
				}
			}
			if(a[0]=='K')
			{
				if(x>num)
					printf("invalid\n");
				else
					printf("%d\n",kamin(head,x));
			}
			if(a[0]=='C')
			{
				top=0;
				co(head,x);
				printf("%d\n",top);
			}
		}
	return 0;
}
