#include<stdio.h>
#include<stdlib.h>

int n, m, t=0;
int g[100][100], disc[100], low[100], parent[100], ap=0, visited=0;

void dfs(int u) {
    visited++;
    disc[u] = low[u] = ++t;
    int child = 0;

    for(int v=1; v<=n; v++) {
        if(g[u][v]) {
            if(disc[v] == 0) {
                parent[v] = u;
                child++;
                dfs(v);
                low[u] = low[u] < low[v] ? low[u] : low[v];
                if(parent[u] == -1 && child > 1) ap = 1;
                if(parent[u] != -1 && low[v] >= disc[u]) ap = 1;
            }
            else if(v != parent[u]) {
                low[u] = low[u] < disc[v] ? low[u] : disc[v];
            }
        }
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&m);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) g[i][j]=0;
        disc[i]=0;
        low[i]=0;
        parent[i] = -1;
    }

    printf("Enter edges (u v):\n");
    for(int i=0; i<m; i++) {
        int u,v;
        scanf("%d %d",&u,&v);
        g[u][v] = g[v][u] = 1;
    }

    dfs(1);

    if(visited != n) printf("Graph is not Biconnected\n");
    else if(ap == 1) printf("Graph is not Biconnected\n");
    else printf("Graph is Biconnected\n");

    return 0;
}