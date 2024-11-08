#include <iostream>
using namespace std;

int ans = 9999;
int region[22][22];
int vis[22][22];
int n, c;
int location[5][2];
int rear=-1, front=-1;

struct queue{
    int row;
    int col;
}Q[10000];

void init(){
    int m, n;
    rear=-1, front=-1;

    for(m=0; m<22; m++){
        for(m=0; n<22; n++)
            vis[m][n]=0;
    }

    for(m=0; m<10000; m++){
        Q[m].row = 0;
        Q[m].col = 0;
    }
}

void discover(int row, int col, int val){
    int l,m,k;
    int cnt=0;

    for(k=0; k<c; k++){
        if(vis[location[k][0]][location[k][1]] > 0)
            cnt++;
    }

    if(cnt >= c)
        return;

    if((row-1)>=1 && vis[row-1][col]==0 && (region[row-1][col]==1 || region[row-1][col]==3)){
        vis[row-1][col] = val+1;
        rear++;
        Q[rear].row = row-1;
        Q[rear].col = col;
    }

    if((row+1)<=n && vis[row+1][col]==0 && (region[row+1][col]==1 || region[row+1][col]==3)){
        vis[row+1][col] = val+1;
        rear++;
        Q[rear].row = row+1;
        Q[rear].col = col;
    }

    if((col-1)>=1 && vis[row][col-1]==0 && (region[row][col-1]==1 || region[row][col-1]==3)){
        vis[row][col-1] = val+1;
        rear++;
        Q[rear].row = row;
        Q[rear].col = col-1;
    }

    if((col+1)<=n && vis[row][col+1]==0 && (region[row][col+1]==1 || region[row][col+1]==3)){
        vis[row][col+1] = val+1;
        rear++;
        Q[rear].row = row;
        Q[rear].col = col+1;
    }

    while(front < rear){
        front++;
        discover(Q[front].row, Q[front].col, vis[Q[front].row][Q[front].col]);
    }
}

int main(){
    int t, test;
    cin >> t;

    for(test=0; test<t; test++){
        int i,j,k;
        int x,y,z;
        int temp=0;
        ans = 9999;
       
        cin >> n >> c;

        for(i=0; i<c; i++){
            cin >> x >> y;
            location[i][0] = x;
            location[i][1] = y;
        }

        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                cin >> region[i][j];
            }
        }

        for(k = 0; k < c; k++){
            region[location[k][0]][location[k][1]] = 3;
        }

        init();
        ans = 9999;
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                init();
                temp=0;

                if(region[i][j]==1){
                    vis[i][j]=1;
                    discover(i,j,1);
                    for(k=0; k<c; k++){
                        if(temp < vis[location[k][0]][location[k][1]])
                            temp = vis[location[k][0]][location[k][1]];
                    }
                    if(ans>temp)
                        ans = temp;
                }
            }
        }
        cout << '#' << test+1 << ans-1;
    }
    return 0;
}