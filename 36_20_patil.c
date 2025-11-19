#include<stdio.h>
#include<stdlib.h>

int main() {
    int n, m;
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&m);

    int g[100][100], indeg[100], q[100], front=0, rear=0;
    for(int i=1; i<=n; i++) {
        indeg[i]=0;
        for(int j=1; j<=n; j++) g[i][j]=0;
    }

    printf("Enter edges (u v):\n");
    for(int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u][v]=1;
        indeg[v]++;
    }

    for(int i=1; i<=n; i++)
        if(indeg[i]==0) q[rear++]=i;

    printf("Topological Order: ");
    int count=0;

    while(front < rear) {
        int u = q[front++];
        printf("%d ",u);
        count++;

        for(int v=1; v<=n; v++) {
            if(g[u][v]) {
                indeg[v]--;
                if(indeg[v]==0)
                    q[rear++]=v;
            }
        }
    }

    if(count != n) printf("\nCycle detected – topological sort not possible.");
    return 0;
}