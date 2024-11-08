#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[10][5];
bool visited[10]={false};
int ans;

int min(int a, int b){
    return a<=b?a:b;
}

int abs(int x){
    return x>=0?x:-x;
}

int dist(int x1, int y1, int x2, int y2){
    return abs(x2-x1)+abs(y2-y1);
}

void solve(int sx, int sy, int dx, int dy, int val){
    ans=min(ans, (dist(sx, sy, dx, dy)+val));
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            visited[i]=true;
            
            solve(arr[i][0], arr[i][1], dx, dy, val+dist(sx, sy, arr[i][2], arr[i][3])+arr[i][4]);
            
            solve(arr[i][2], arr[i][3], dx, dy, val+dist(sx, sy, arr[i][0], arr[i][1])+arr[i][4]);
            
            visited[i]=false;
        }
    }
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        int sx,sy,dx,dy;
        cin>>sx>>sy>>dx>>dy;
        ans=1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin>>arr[i][j];
            }
        }
        solve(sx, sy, dx, dy, 0);
        cout<<ans<<endl;
    }
    return 0;
}