#include <stdio.h>
#include <stdlib.h>

int n, m, idx, key[20];
int count = 0;
int *ht;

void insert(int k) {
  idx = k % m;
  while (ht[idx] != -1) {
    idx = (idx + 1) % m;
  }
  ht[idx] = k;
  count++;
}

void display() {
  if (count == 0) {
    printf("Enpty\n");
    return;
  } else {
    printf("Content Of hash table\n");
    for (int i = 0; i < m; i++) {
      printf("%d ", ht[i]);
    }
  }
}

int main() {
  printf("enter the number of keys\n");
  scanf("%d", &n);
  printf("enter the number of Memory location\n");
  scanf("%d", &m);

  printf("Start\n");
  for (int i = 0; i < n; i++) {
    printf("Enter keys \n");
    scanf("%d", &key[i]);
  }
  ht = (int *)malloc(m * sizeof(int));
  for (int i = 0; i < n; i++) {
    ht[i] = -1;
  }
  for (int i = 0; i < n; i++) {
    if (count == m) {
      printf("FULL\n");
      break;
    } else {
      insert(key[i]);
    }
  }
  display();
  free(ht);
  return 0;
}
