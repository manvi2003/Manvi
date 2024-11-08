#include <iostream>
using namespace std;

int sx,sy,dx,dy;
int n;
int a[12][12];
int x[12][2];
int mod(int a){
    if(a<0)return -a;
    return a;
}

int dp[2048][12];
int distance(int a,int b,int c,int d){
    return  mod(a-c) + mod(b-d);  
}

int visited_all;
int tsp(int mask,int cur){
    if(mask==visited_all)return distance(x[cur][0],x[cur][1],dx,dy);
    if(dp[mask][cur]!=-1)return dp[mask][cur];
    int ans=100000;
    for(int i=0;i<n+1;i++){
        if((mask & (1<<i))==0){
            
            ans=min(ans,a[cur][i]+tsp((mask | (1<<i)) ,i));
            
        }
    }
    dp[mask][cur]=ans;
    return dp[mask][cur];
}

int main() {
    for(int i=0;i<10;i++){
    cin>>n;
    for(int i=0;i<2048;i++)for(int j=0;j<12;j++)dp[i][j]=-1;
    visited_all=(1<<(n+1))-1;
       
    cin>>sx>>sy>>dx>>dy;
    x[0][0]=sx;
    x[0][1]=sy;
    for(int i=0;i<n;i++){
        int c,d;
        cin>>c>>d;
        x[i+1][0]=c;
        x[i+1][1]=d;
    }
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            a[i][j]=distance(x[i][0],x[i][1],x[j][0],x[j][1]);
        }
    }
    int ans=tsp(1,0);
    cout<<"# "<<i+1<<" "<<ans<<endl;
    }
    return 0;
}