#include <iostream>
#define size 20
using namespace std;

int N, M, K;
int arr[size][size];
int count_ = 0, res;
void flip_col(int index) {
    for(int i = 1; i <= N; i++)
        arr[i][index] = (arr[i][index] ? 0 : 1); 
}
int count_row() {
    int n = 0;
    for(int i = 1; i <= N; i++) {
        int flag = 1;
        for(int j = 1; j <= M; j++) {
            if(arr[i][j] != 1) {
                flag = 0;
                break;
            }
        }
        if(flag) n++;
    }
    return n;
}

void backtrack(int index, int K) {
    if(K <= 0) {
        int temp = count_row();
        if(res < temp)
            res = temp;
        return;
    }
    if(index > M) 
        return;
    for(int i = 0; i <= K; i++) {
        for(int j = 0; j < i; j++) flip_col(index);
        backtrack(index + 1, K - i);
        for(int j = 0; j < i; j++) flip_col(index);
    }
}
int main() {
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            cin >> arr[i][j];
    res = 0;
    backtrack(1, K);
    cout << res << endl;
    return 0;
}