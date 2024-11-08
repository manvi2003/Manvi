#include<iostream>
using namespace std;

bool comp(int m, int a[], int n, int k){
    int curr=1;
    int leftCow = 0;

    for(int i=1; i<n; i++){
        if(a[i]-a[leftCow] >= m){
            curr++;
            leftCow = i;
            if(curr==k)
                return true;
        }
    }
    return false;
}

void sort(int a[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(a[j] > a[j+1]){
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

int main(){
    int t, test;
    cin >> test;

    for(t=0; t<test; t++){
        int n,k;
        cin >> n >> k;
        int a[100000];
        for(int i=0; i<n; i++)
            cin >> a[i];

        sort(a,n);

        int l=0, r=a[n-1]-a[0]+1;
        while(r>l){
            int m = (l+r+1)/2;
            if(comp(m,a,n,k)==true)
                l = m;
            else
                r = m-1;
        }
        cout << l << '\n';
    }
}