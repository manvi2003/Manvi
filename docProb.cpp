#include<iostream>
using namespace std;

const int N = 30;

void docprob(double graph[N][N], int nodes, int time, int currNode, double p, double ans[N]){
    if(time<=0){
        ans[currNode] += p;
        return;
    }

    bool hasNeighbour = false;
    for(int i=0; i<nodes; i++){
        if(graph[currNode][i]!=0){
            hasNeighbour = true;
            double tempProb = p*graph[currNode][i];
            docprob(graph,nodes,time-10,i,tempProb,ans);
        }
    }

    if(!hasNeighbour)
        ans[currNode] += p;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int nodes, edges, time;
        cin >> nodes >> edges >> time;

        double arr[N][N] = {0};

        int from, to; double prob;
        for(int i=0; i<edges; i++){
            cin >> from >> to >> prob;
            arr[from-1][to-1] = prob;
        }

        double ans[N] = {0.0};
        docprob(arr,nodes, time, 0, 1.0, ans);

        double finalProb = 0.0;
        int finalDiv = 0;

        for(int i=0; i<nodes; i++){
            if(ans[i] > finalProb){
                finalProb = ans[i];
                finalDiv = i+1;
            }
        }
        cout << finalDiv << " " << finalProb << endl;
    }

    return 0;
}