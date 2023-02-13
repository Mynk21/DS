#include <stdio.h>
#include <stdlib.h>
int adj[20][20], n, vis[50], q[20], front = -1, rear = -1, curr;

void bfs(int v) {
  vis[v] = 1;
  q[++rear] = v; // insert in queue
  while (front != rear) {
    curr = q[++front]; // removing
    for (int i = 1; i <= n; i++) {
      if (adj[curr][i] == 1 && vis[i] == 0) {
        q[++rear] = i;
        vis[i] = 1;
        printf("%d ", i);
      }
    }
  }
}

void dfs(int v) {
  vis[v] = 1;
  for (int i = 1; i < n; i++) {
    if (adj[v][i] == 1 && vis[i] == 0) {
      vis[i] = 1;
      printf("%d ", i);
      dfs(i);
    }
  }
  return;
}

int main() {
  printf("Enter number of vertex\n");
  scanf("%d", &n);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &adj[i][j]);
  for (int i = 0; i <= n; i++)
    vis[i] = 0;
  printf("enter the Starting vertex\n");
  int v;
  scanf("%d", &v);
  int ch;
  printf("1.bfs\n2.dfs\n");
  printf("Enter the choise\n");
  scanf("%d", &ch);
  switch (ch) {
  case 1:
    printf("BFS nodes rechable from %d \n", v);
    bfs(v);
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        printf("Vertex Not rechable %d", i);
      }
    }
    printf("\n");
    break;

  case 2:

    printf("DFS nodes rechable from %d \n", v);
    dfs(v);
    for (int i = 1; i <= n; i++) {
      if (vis[i] == 0) {
        printf("Vertex Not rechable %d", i);
      }
    }
    printf("\n");
    break;
  }
}
// 0 1 1 0 0
// 0 0 0 1 0
// 0 0 0 0 0
// 0 0 1 0 0
// 0 0 1 0 0
// 243,5NR
