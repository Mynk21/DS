#include <stdio.h>
#include <stdlib.h>

struct bst {
  struct bst *lchild;
  int data;
  struct bst *rchild;
};

void insert(struct bst **root, int x) {
  struct bst *temp, *p;
  temp = (struct bst *)malloc(sizeof(struct bst));
  temp->lchild = NULL;
  temp->data = x;
  temp->rchild = NULL;
  if (*root == NULL) {
    *root = temp;

  } else {
    p = *root;
    while (1) {

      if (p->data == temp->data) {
        free(temp);
        break;
      } else if (p->data < temp->data) {
        if (p->rchild == NULL) {
          p->rchild = temp;
          break;
        }
        p = p->rchild;
      } else {
        if (p->lchild == NULL) {
          p->lchild = temp;
          break;
        }
        p = p->lchild;
      }
    }
  }
}

void inorder(struct bst *r) {
  if (r != NULL) {
    inorder(r->lchild);
    printf("%d ", r->data);
    inorder(r->rchild);
  }
}
void preorder(struct bst *r) {
  if (r != NULL) {
    printf("%d ", r->data);
    preorder(r->lchild);
    preorder(r->rchild);
  }
}
void postorder(struct bst *r) {
  if (r != NULL) {
    postorder(r->lchild);
    postorder(r->rchild);
    printf("%d ", r->data);
  }
}
int search(struct bst *r, int x) {
  while (r != NULL) {
    if (r->data == x)
      return 1;
    else if (r->data < x)
      r = r->rchild;
    else
      r = r->lchild;
  }
  return 0;
}

int main() {
  struct bst *root = NULL;
  int c, x, n;
  printf("\n1.create\n2.inorder\n3.preorder\n4.postorder\n5.search\n6.exit ");
  while (1) {
    printf("\nenter your choice ");
    scanf("%d", &c);
    switch (c) {
    case 1:
      printf("enter the number of nodes ");
      scanf("%d", &n);
      printf("enter the data :");
      for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&root, x);
      }
      break;
    case 2:
      inorder(root);
      break;
    case 3:
      preorder(root);
      break;
    case 4:
      postorder(root);
      break;
    case 5:
      printf("enter the value u want to search ");
      scanf("%d", &x);
      printf("%d ", search(root, x));
      break;
    case 6:
      return 0;
    }
  }
  return 0;
}

// : 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
