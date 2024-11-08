#include <iostream>
using namespace std;

int n;
int arr[15][5];

int solve(int x, int y, bool check, int index){
    if(x<0 || (arr[x][y]==2 && index>=5))
        return 0;
    
    int ans = 0;
    int next[3][2] = {{-1, -1}, {-1, 0}, {-1, 1}};

    for(int i=0;i<3;i++){
        int dx = x+next[i][0];
        int dy = y+next[i][1];
        int p = 0;

        if(dx>=0 && dx<n && dy>=0 && dy<5){
            if(arr[dx][dy]==1 && check==false)
                p=1+solve(dx, dy, false, index);
            
            else if(arr[dx][dy]==1 && check==true)
                p=1+solve(dx, dy, true, index+1);
            
            else if(arr[dx][dy]==2 && check==false)
                p=solve(dx, dy, true, index+1);
            
            else if(arr[dx][dy]==2 && check==true)
                p=solve(dx, dy, true, index+1);
            
            else if(arr[dx][dy]==0 && check==false)
                p=solve(dx, dy, check, index);
            
            else if(arr[dx][dy]==0 && check==true)
                p=solve(dx, dy, check, index+1);
        }

        ans = max(ans, p);
    }
    
    return ans;
    
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    int m = 1;
    while(t--){
        cin >> n;
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                cin >> arr[i][j];
            }
        }
        cout << "#" << m << " " << solve(n, 2, false, 0) << endl;
        m++;
    }
    return 0;
}