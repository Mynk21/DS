#include <stdio.h>
#include <stdlib.h>
struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *create(int data) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
  }

struct node* insert(struct node * root,int data){
  if(root==NULL){
    root=create(data);
  }else if(root->data > data){
    root->left =insert(root->left,data);
  }else{
    root->right =insert(root->right,data);
  }
  return root;
}

void inorder(struct node* root){
  if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}

void preorder(struct node *r) {
  if (r != NULL) {
    printf("%d ", r->data);
    preorder(r->lchild);
    preorder(r->rchild);
  }
}
void postorder(struct node * r) {
  if (r != NULL) {
    postorder(r->lchild);
    postorder(r->rchild);
    printf("%d ", r->data);
  }
}


int main(){
  int  n;
  struct node * root =NULL;
  printf("Enter n\n");
  scanf("%d",&n);
  for(int i = 0 ; i< n;i++){
    int x ;
    printf("Enter data\n");
  scanf("%d",&x);
   root= insert(root,x);
  }

  inorder(root);
  postorder(root);
  preorder(root);
}
