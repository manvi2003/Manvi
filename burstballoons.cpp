#include<iostream>
using namespace std;

int n;
int num[100];
int dp[100][100];

int solve(int i, int j){
    if(i==j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    int maxi = -1e9;
    for(int k=i; k<j; k++){
        int score;
        if(i==1 && j==n+1)
            score = num[j]*num[k]*num[i-1] + solve(i,k)+solve(k+1,j);
        else   
            score = num[i-1]*num[j] + solve(i,k)+solve(k+1,j);

        maxi = max(maxi,score);
    }

    return dp[i][j] = maxi;
}

int main(){
    cin >> n;
    num[0] = 1;
    for(int i=0; i<n+2; i++){
        for(int j=0; j<n+2; j++)
            dp[i][j] = -1;
    }

    for(int i=1; i<=n; i++)
        cin >> num[i];
    num[n+1] = 1;

    cout << solve(1,n+1) << endl;

    return 0;
}