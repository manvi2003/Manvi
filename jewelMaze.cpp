#include<iostream>
#include<climits>
#define MAX 21
using namespace std;

int n, ans;

bool isValid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<n);
}

void printMatrix(int **arr){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout << arr[i][j] << " ";	
		cout << endl;
	}
}

int dirX[] = {1,0,-1,0};
int dirY[] = {0,1,0,-1};

void jewelMaze(int **maze, int x, int y, int value, int **visited, int **path){
	if(x == n-1 && y == n-1){
		if(value >= ans){
			ans = value;
			
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++)
				    if(visited[i][j]){
				    	path[i][j] = 3;
					}
					else{
						path[i][j] = maze[i][j];
					}	
			}
		}
		return;
	}

	for(int i=0; i<4; i++){
		int newX = x + dirX[i];
		int newY = y + dirY[i];
		
		if(isValid(newX, newY)){
			
			if(visited[newX][newY] == 0 && maze[newX][newY] == 0){
				visited[newX][newY] = 1;
				jewelMaze(maze, newX, newY, value, visited, path);
				visited[newX][newY] = 0;
			}
			
			if(visited[newX][newY] == 0 && maze[newX][newY] == 2){
				visited[newX][newY] = 1;
				jewelMaze(maze, newX, newY, value+1, visited, path);
				visited[newX][newY] = 0;
			}

		}
	}
	
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		int **maze = new int * [n + 1];
		for(int i=0; i<n; i++){
			maze[i] = new int[n + 1];
		}
		
		int **visited = new int * [n + 1];
		for(int i=0; i<n; i++){
			visited[i] = new int[n + 1];
		}
		
		int **path = new int * [n + 1];
		for(int i=0; i<n; i++){
			path[i] = new int[n + 1];
		}

		// Cleaner and input Maze
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cin >> maze[i][j];
				visited[i][j] = 0;
				path[i][j] = 0;
			}
		}
		
		ans = INT_MIN;
		
		int sX = 0, sY = 0;
		visited[sX][sY] = 1;
		
		if(maze[sX][sY] == 2)
			jewelMaze(maze, sX, sY, 1, visited, path);
		else
			jewelMaze(maze, sX, sY, 0, visited, path);
			
			
		cout << "Jewel collected : " << ans << endl;
		
		cout << "Path traversed --> " << endl;
		printMatrix(path); 
		
		cout << endl;
	}
	return 0;
}