#include<stdio.h>
#include<stdlib.h>
struct node{
//tree structure
	int data ;
	struct node *left;
	struct node *right;
};
struct node* create(int data){
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}
int height(struct node *root){
	int lh , rh;
	if(root==NULL)
		return 0;
	else{
		lh = height(root->left);
		rh = height(root->right);
		if(lh>rh)
			return lh+1;
		else 
			return rh+1;
	
	}
}
void PrintCurrentLevel(struct node *root,int level){
	if(root==NULL)
		return ;
	if(level==1){
		printf(" %d ",root->data);
	}
	else{
		PrintCurrentLevel(root->left,level-1);
		PrintCurrentLevel(root->right,level-1);
	}
}
void PrintlevelOrder(struct node *root){
	int h = height(root);
	for(int i = 1 ; i<=h ; i++){
		PrintCurrentLevel(root,i);
			printf("\n");
	}
}
int main(){
	struct node* root  = create(1);
	root->left=create(2);
	root->right=create(3);
	root->left->left=create(4);
	root->left->right=create(5);
	root->right->right=create(6);
	root->right->left=create(5);
	PrintlevelOrder(root);
	printf("\n");
}


