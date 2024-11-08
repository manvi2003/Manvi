#include<iostream>
using namespace std;

int arr[1000][1000];
bool visited[1000];
int ans = 1000000;

void dfs(int n,int count,int cost,int last){
    if(count==n){
        int cost1 = cost + arr[last][0];
        if(cost1<ans)
            ans = cost1;
    }

    for(int i=1;i<n;i++){
        if(visited[i])
            continue;
        if(arr[last][i]==0)
            continue;
        visited[i]=true;
        int cost1 = cost + arr[last][i];
        dfs(n,count+1,cost1,i);
        visited[i]=false;
    }

    return;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ans = 1000000;
        cin>>n;
        for(int i=0;i<n;i++)
            visited[i]=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
               cin>>arr[i][j];
           }
        }

        dfs(n,1,0,0);
        cout<<ans<<endl;
    }
}