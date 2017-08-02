#include<stdlib.h>
#include<stdio.h>
#define HEIGHT 1
int sea=0;
struct node
{
	int data;
	int lc;
	int rc;
	struct node* left;
	struct node* right;
	int height;
};
int answer =0;
struct node* get_node(int val){
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->left = NULL;
	new_node->lc=0;
	new_node->rc=0;
	new_node->right = NULL;
	new_node->data = val;
	new_node->height = HEIGHT;
	return new_node;
}

int ksmal(struct node*root,int val)
{
	if(root==NULL)
	{
		return 0;
	}
	int num=(root->lc)+1;

//	printf("val:%d num:%d\n",val,num);
	if(val==num)
	{
		return root->data;
	}

	else if(val<num)
	{
		return ksmal(root->left,val);
	}
	else
	{
		return ksmal(root->right,val-num);
	}
	return 0;
}

int count(struct node*root,int value)
{

	if(root!=NULL)
	{
	int num=root->data;
	if(value>num)
	{
		answer=answer+(root->lc)+1;
		return count(root->right,value);
	}
	else
	{
		return count(root->left,value);
	}
}
	return 0;
}

int get_height(struct node* root){
	if(!root)
		return 0;
	else
		return root->height;
}

int get_balance(struct node* root){
	if(!root)
		return 0;
	return (get_height(root->left) - get_height(root->right));
}
int max(int a, int b){
	return (a > b) ? a : b;
}
struct node* left_rotate(struct node* root){
	struct node* right = root->right;
	int l1=root->lc,l2=right->lc;
	struct node* left = right->left;
	//perform rotation
	right->left = root;
	root->right = left;
	root->rc=l2;
  right->lc=l1+l2+1;
	//update heights
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	right->height = max(get_height(right->left), get_height(right->right)) + 1;
	return right;
}
struct node* right_rotate(struct node* root){
	struct node* left = root->left;
	struct node* right = left->right;
	int r1=root->rc,r2=left->rc,r3=root->lc;
	left->right = root;
	root->left = right;
	root->lc=r2;
	left->rc=root->lc+root->rc+1;
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	left->height = max(get_height(left->left), get_height(left->right)) + 1;
	return left;
}
struct node* insert(struct node* root, int val){
	//normal insertion
	if(!root){
		struct node* new_node = get_node(val);
		return new_node;
	}
	if(root->data > val)
		{
			root->lc=root->lc+1;
			root->left = insert(root->left, val);
		}
	else if(root->data < val)
	{
		root->rc=root->rc+1;
		root->right = insert(root->right, val);
	}
	//update height of root
	root->height = max(get_height(root->left), get_height(root->right)) + 1;
	//check for balancing
	int balance = get_balance(root);
	//left-left case
	if(balance > 1 && root->left->data > val){
		root = right_rotate(root);
	}
	//right-right case
	else if(balance < -1 && root->right->data < val){
		root = left_rotate(root);
	}
	//left-right case

	else if(balance > 1 && root->left->data < val){
		root->left = left_rotate(root->left);
		root = right_rotate(root);
	}
	//right-left case
	else if(balance < -1 && root->right->data > val){
		root->right = right_rotate(root->right);
		root = left_rotate(root);
	}
	return root;
}
struct node* balance_tree(struct node* root){
	struct node* x, *y;
	int lheight,rheight;
	lheight = get_height(root->left);
	rheight = get_height(root->right);
	if(lheight >= rheight)
		x = root->left;
	else
		x = root->right;
	lheight = get_height(x->left);
	rheight = get_height(x->right);
	if(x == root->left){
		if(lheight >= rheight){
			y = x->left;
		}
		else
			y = x->right;
	}
	if(x == root->right){
		if(lheight > rheight){
			y = x->left;
		}
		else
			y = x->right;
	}
	//left-left case
	if(root->left == x && x->left == y){
		root = right_rotate(root);
	}
	//right-right case
	else if(x == root->right && x->right == y){
		root = left_rotate(root);
	}
	//left-right case
	else if(x == root->left && y == x->right){
		root->left = left_rotate(root->left);
		root = right_rotate(root);
	}
	//right-left case
	else if(x == root->right && y == x->left){
		root->right = right_rotate(root->right);
		root = left_rotate(root);
	}
	return root;
}
struct node* inorder_succ_right_tree(struct node* root){
	struct node* temp = root->right;
	while(temp->left){
		temp = temp->left;
	}
	return temp;
}
void search(struct node* root,int val)
{
	if(root==NULL)
	{
		//printf("%d not found\n",dat);
		return;
	}
	if(root->data==val)
	{
		//printf("%d found\n",dat);
		sea = 1;
	}
	else
	{
		if(val>root->data)
			search(root->right,val);
		else
			search(root->left,val);
	}
}
struct node* deletion(struct node* root, int val){
	//normal deletion
	if(!root)
		return NULL;
	if(root->data > val){
		root->lc=root->lc-1;
		root->left = deletion(root->left, val);
	}
	else if(root->data < val){
		root->rc=root->rc-1;
		root->right = deletion(root->right, val);
	}
	else{
		struct node* temp;
		if(root->left == NULL || root->right == NULL){
			if(root->left)
				temp = root->left;
			else if(root->right)
				temp = root->right;
			else
				temp = NULL;
			root = NULL;
			free(root);
			return temp;
		}
		else{
			temp = inorder_succ_right_tree(root);
			root->data = temp->data;
			root->rc--;
			root->right = deletion(root->right,temp->data);
		}
	}
	if(root){
		//update height
		root->height = max(get_height(root->left), get_height(root->right)) + 1;
		int balance = get_balance(root);
		if(balance > 1 || balance < -1)
			root = balance_tree(root);
	}
	return root;
}
void inorder(struct node* root){
	if(!root)
		return;
	inorder(root->left);
	printf("Value:%d Height:%d LC:%d RC%d\n",root->data,root->height,root->lc,root->rc);
	inorder(root->right);
}
int main()
{
	int n,num,q;
	char cha[10];
	struct node*root=NULL;
	scanf("%d",&q);
	while(q--)
     {
			 sea=0,answer=0;
         scanf("%s %d",cha,&num);
         if(cha[0]=='I')
         {
				//	 printf("hi1\n");
					 search(root,num);
					// printf("hi2\n");
	 				if(sea==0)
             {
							 root=insert(root,num);
						 }
  //        inorder(root);
         }
         else if(cha[0]=='D')
         {
					  search(root,num);
	 				if(sea==1)
             {
							 root=deletion(root,num);
						 }
        //       inorder(root);
         }
         else if(cha[0]=='C')
         {
             if(root==NULL)
                 printf("0\n");
             else
             {
                 count(root,num);
          //       inorder(root);
                 printf("%d\n",answer);
             }
         }
         else if(cha[0]=='K')
         {
             if(root==NULL)
                 printf("invalid\n");
             else if(num>((root->lc)+(root->rc)+1))
                 printf("invalid\n");
             else
             {
                 int fans=ksmal(root,num);
              // inorder(root);
                 printf("%d\n",fans);
             }
         }
     }
     return 0;
}
