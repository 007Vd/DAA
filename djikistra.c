#include<stdio.h>
#include<limits.h>
#define MAX 100
#define INF INT_MAX

int min_dist(int dist[],int visited[],int n){
    int min=INF;
    int min_index=-1;
    for(int v=0;v<n;v++){
        if(!visited[v] && dist[v]<min){
            min=dist[v];
            min_index=v;
        }
    }
    return min_index;
}

void djikistra(int graph[MAX][MAX],int src,int n){

    int dist[MAX];
    int visited[MAX];
    for(int v=0;v<n;v++){
        dist[v]=INF;
        visited[v]=0;

    }
dist[src]=0;
for(int c=0;c<n-1;c++){
    int u=min_dist(dist,visited,n);
     if (u==-1) break;
    visited[u]=1;
    for(int v=0;v<n;v++){
        if(!visited[v] && graph[u][v] && dist[u]!=INF && dist[v]>dist[u]+graph[u][v]){
            dist[v]=dist[u]+graph[u][v];
        }

    }
}
printf("shortest distnace from src %d\n",src+1);
printf("vertex\t distance\n");
for(int i=0;i<n;i++){
printf("%d\t",i+1);
if(dist[i]==INF)
printf("INF\n");
else printf("%d\n",dist[i]);
}
}

int main(){
    int n;
    printf("Enter number of vertices:");
    scanf("%d",&n);

    int graph[MAX][MAX];
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            scanf("%d",&graph[i][j]);
        }}

    int src;
    printf("Enter source vertex (1 to %d): ", n);
    scanf("%d",&src);
    src--;
    djikistra(graph,src,n);
}