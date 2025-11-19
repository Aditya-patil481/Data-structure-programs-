#include<stdio.h>
#include<stdlib.h>

int a[50][50], visited[50], q[50], n, f, r;

void bfs(int v) {
    int i;
    f = r = 0;
    q[r] = v;
    visited[v] = 1;
    while(f <= r) {
        v = q[f++];
        printf("%d ", v);
        for(i=1; i<=n; i++) {
            if(a[v][i] == 1 && visited[i] == 0) {
                q[++r] = i;
                visited[i] = 1;
            }
        }
    }
}

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);
    for(i=1; i<=n; i++) {
        if(a[v][i] == 1 && visited[i] == 0)
            dfs(i);
    }
}

int main() {
    int i, j, v, ch;
    printf("Enter no. of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(i=1; i<=n; i++) {
        for(j=1; j<=n; j++)
            scanf("%d",&a[i][j]);
    }

    while(1) {
        printf("\n1.BFS\n2.DFS\n3.Exit\nEnter choice: ");
        scanf("%d",&ch);

        if(ch==3) break;

        for(i=1; i<=n; i++) visited[i] = 0;

        printf("Enter starting vertex: ");
        scanf("%d",&v);

        if(ch==1) {
            printf("BFS: ");
            bfs(v);
        }
        else if(ch==2) {
            printf("DFS: ");
            dfs(v);
        }
    }
    return 0;
}