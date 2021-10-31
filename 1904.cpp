#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1000001];
long long recur(long long n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return dp[n] = 1;
    }
    else if(n==2){
        return dp[n] = 2;
    }
    if(dp[n]){
        return dp[n];
    }
    return dp[n] = (recur(n-2) + recur(n-1))%15746;
}
int main(){
    long long N;
    cin>>N;
    cout<<recur(N);
    return 0;
}