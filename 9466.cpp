#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int T,N;
int arr[100001];
vector<int> dp[100001];
void recur(int n){
    queue<int> q;
    q.push(int n);
    while(!q.empty()){

    }
}
int main(){
    cin>>T;
    for(int i=1;i<=T;++i){
        cin>>N;
        for(int j=1;j<=N;++j){
            cin>>arr[j];
            dp[j].push_back(arr[j]);
            dp[arr[j]].push_back(j);
        }
    }
    return 0;
}