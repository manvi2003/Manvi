#include<iostream>
using namespace std;

struct Node{
    bool up,down,left,right;
};

struct Point{
    int x,y;
};

int n,m,r,c,len;
int arr[1005][1005];
int vis[1005][1005], dist[1005][1005];

int result;
Node pipes[1005][1005];
Point q[1000005];

bool isValid(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = 0;
            dist[i][j] = 0;
        }
    }

    int front=0, rear=0;
    
    dist[r][c]=1;
    vis[r][c]=1;
    if(arr[r][c]==0){
        result=0;
        return;
    }

    q[rear].x = r;
    q[rear].y = c;
    rear = (1+rear)%1000005;

    while(front!=rear){
        int a = q[front].x;
        int b = q[front].y;
        front = (front+1)%1000005;

        if(1+dist[a][b] <= len){
            if(isValid(a-1,b) && !vis[a-1][b] && pipes[a-1][b].down && pipes[a][b].up){
                vis[a-1][b] = 1;
                dist[a-1][b] = 1+dist[a][b];
                result++;

                q[rear].x = a-1;
                q[rear].y = b;
                rear = (rear+1)%1000005;
            }
        }

        else if(1+dist[a][b] <= len){
            if(isValid(a-1,b) && !vis[a-1][b] && pipes[a-1][b].down && pipes[a][b].up){
                vis[a-1][b] = 1;
                dist[a-1][b] = 1+dist[a][b];
                result++;

                q[rear].x = a-1;
                q[rear].y = b;
                rear = (rear+1)%1000005;
            }

            else if(isValid(a+1,b) && !vis[a+1][b] && pipes[a+1][b].up && pipes[a][b].down){
                vis[a+1][b] = 1;
                dist[a+1][b] = 1+dist[a][b];
                result++;

                q[rear].x = a+1;
                q[rear].y = b;
                rear = (rear+1)%1000005;
            }

            else if(isValid(a,b+1) && !vis[a][b+1] && pipes[a][b+1].left && pipes[a][b].right){
                vis[a][b+1] = 1;
                dist[a][b+1] = 1+dist[a][b];
                result++;

                q[rear].x = a;
                q[rear].y = b+1;
                rear = (rear+1)%1000005;
            }

            else if(isValid(a,b-1) && !vis[a][b-1] && pipes[a][b-1].right && pipes[a][b].left){
                vis[a][b-1] = 1;
                dist[a][b-1] = 1+dist[a][b];
                result++;

                q[rear].x = a;
                q[rear].y = b-1;
                rear = (rear+1)%1000005;
            }
        }   
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        result=1;
        cin >> n >> m >> r >> c >> len;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> arr[i][j];

                if(arr[i][j]==1){
                    pipes[i][j].up = true;
                    pipes[i][j].down = true;
                    pipes[i][j].left = true;
                    pipes[i][j].right = true;
                }

                if(arr[i][j]==2){
                    pipes[i][j].up = true;
                    pipes[i][j].down = true;
                    pipes[i][j].left = false;
                    pipes[i][j].right = false;
                }

                if(arr[i][j]==3){
                    pipes[i][j].up = false;
                    pipes[i][j].down = false;
                    pipes[i][j].left = true;
                    pipes[i][j].right = true;
                }

                if(arr[i][j]==4){
                    pipes[i][j].up = true;
                    pipes[i][j].down = false;
                    pipes[i][j].left = false;
                    pipes[i][j].right = true;
                }

                if(arr[i][j]==5){
                    pipes[i][j].up = false;
                    pipes[i][j].down = true;
                    pipes[i][j].left = false;
                    pipes[i][j].right = true;
                }

                if(arr[i][j]==6){
                    pipes[i][j].up = false;
                    pipes[i][j].down = true;
                    pipes[i][j].left = true;
                    pipes[i][j].right = false;
                }

                if(arr[i][j]==7){
                    pipes[i][j].up = true;
                    pipes[i][j].down = false;
                    pipes[i][j].left = true;
                    pipes[i][j].right = false;
                }

                else{
                    pipes[i][j].up = false;
                    pipes[i][j].down = false;
                    pipes[i][j].left = false;
                    pipes[i][j].right = false;
                }
            }
        }

        bfs();
        cout << result << "\n";
    }

    return 0;
}