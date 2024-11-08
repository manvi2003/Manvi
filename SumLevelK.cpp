#include <iostream>
#define size 1500
using namespace std;

int K;
char s[size];

int strlen(char s[]) {
    int i = 0;
    while(s[i]) i++;
    return i;
}

int cal_sum(char s[], int K) {
    int sum_ = 0, k = -1;
    int length = strlen(s);
    for(int i = 0; i < length; i++) {
        if(s[i] == '(') k++;
        else if(s[i] == ')') k--;
        else { 
            if(k == K) {
                int n = 0;
                while(s[i] >= '0' && s[i] <= '9')
                    n = n * 10 + s[i++] - '0';
                sum_ += n;
                i--;
            }
        }
    }
    return sum_;
}

int main() {
    cin >> K >> s;
    int res = cal_sum(s, K);
    cout << res << endl;
}