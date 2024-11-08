#include<iostream>
using namespace std;

int n,m;
int dfsvis[15]={0}, vis[15]={0}, sum[15]={0}, ans[15];
int adj[15][15];
int mini = 1e9;
int cycleLen=0;

int dfs(int node, int parent){
    dfsvis[node] = dfsvis[parent] + 1;
    sum[node] += node + sum[parent];
    vis[node] = 1;

    for(int i=1; i<=n; i++){
        if(adj[node][i]==-1) continue;
        int neighbour = i;
        if(dfsvis[neighbour]){// && neighbour!=parent
            int cycleSum = sum[node] - sum[neighbour] + neighbour;
            if(cycleSum<mini){
                int z = 0;
                for(int k=1; k<=n; k++){
                    if(dfsvis[k]>=dfsvis[neighbour] && dfsvis[k]<=dfsvis[node]){
                        ans[z] = k;
                        z++;
                    }
                }
                cycleLen=z;
                mini = cycleSum;
            }
        }
        else if(!dfsvis[neighbour])
            dfs(neighbour,node);
    }
    sum[node]=0;
    dfsvis[node]=0;
}

int main(){
    cin >> n >> m;
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            adj[i][j] = -1;

    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        //adj[v][u] = 1
    }

    for(int i=1; i<=n; i++){
        if(!vis[i])
            dfs(i,0);
    }

    for(int i=0; i<cycleLen; i++)
        cout << ans[i] << " ";
    
    cout << endl;

    return 0;
}