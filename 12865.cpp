//https://www.acmicpc.net/problem/12865
#include<iostream>
#include<algorithm>
using namespace std;
int N,K;
int v[101];
int w[101];
int dp[101][100001];
int bag(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=K;++j){
            if(j>=w[i]){
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[N][K];
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cin>>N>>K;
    for(int i=1;i<=N;++i){
        cin>>w[i]>>v[i];
    }
    cout<<bag()<<'\n';
    return 0;
}//DP  0/1 Knapsack