#include<iostream>
using namespace std;

int n, k;

void merger(int *overflow_numbers, int l, int m, int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int *L = new int[n1];
    int *R = new int[n2];

    for(int i=0; i<n1; i++){
        L[i]=overflow_numbers[l+i];
    }
    for(int j=0; j<n2; j++){
        R[j]=overflow_numbers[m+1+j];
    }


    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            overflow_numbers[k]=L[i];
            i++;
        }else{
            overflow_numbers[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        overflow_numbers[k]=L[i];
        k++;
        i++;
    }
    while(j<n2){
        overflow_numbers[k]=R[j];
        k++;
        j++;
    }

    delete[] L;
    delete[] R;
}


void merge_sort(int *overflow, int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        merge_sort(overflow, l, m);
        merge_sort(overflow, m+1, r);
        merger(overflow, l, m, r);
    }
}

int minCrowPotStoneSecond(int *overflow_numbers){
    int total_stones=0;

    for(int i=n-1; i>0; i--){
        overflow_numbers[i] = max(0,overflow_numbers[i]-overflow_numbers[i-1]);
    }

    for(int i=0; i<k; i++){
        total_stones+=(overflow_numbers[i]*(n-i));
    }
    return total_stones;
}

int main(){
	cin >> n;
	int *arr = new int[n + 1];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cin >> k;

    merge_sort(arr, 0, n-1);
	
	cout << minCrowPotStoneSecond(arr);
	return 0;
}