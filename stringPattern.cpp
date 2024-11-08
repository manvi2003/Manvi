#include<iostream>
using namespace std;

int patternCount(string S){
    // Variable to store the last character
    char last = S[0];

    int i = 1, counter = 0;
    while (i < S.size()){
        // We found 0 and last character was '1', state change
        if (S[i] == '0' && last == '1')
        {
            while (S[i] == '0')
                i++;

            // After the stream of 0's, we got a '1', counter incremented
            if (S[i] == '1')
                counter++;
        }

        // Last character stored
        last = S[i];
        i++;
    }

    return counter;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        cout << patternCount(S) << endl;
    }
    return 0;
}