#include <iostream>
#include <algorithm>
using namespace std;
int P[20];
int T[20];
int dp[20];
int N;
int consult(int n){
    if(dp[n]){
        return dp[n];
    }
    if(n>N){
        return 0;
    }
    if(T[n]<=N-n+1){
        return dp[n] = max(consult(n+T[n])+P[n],consult(n+1));
    }
    else{
        return  dp[n] = consult(n+1);
    }
}
int main(){
    int maxi=0;
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>T[i]>>P[i];
    }
    for(int i=1;i<=N;++i){
        if(maxi<consult(i)){
            maxi = consult(i);
        }
    }
    cout<<maxi;
    return 0;
}