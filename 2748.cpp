#include <iostream>
#include <algorithm>
using namespace std;
long long dp[10001];
long long fibo(long long n){
    if(n==0){
        return 0;
    }
    else if(n==1||n==2){
        dp[n] = 1;
        return 1;
    }
    if(dp[n]){
        return dp[n];
    }
    return dp[n] = fibo(n-2) + fibo(n-1);
}
int main(){
    long long N;
    cin>>N;
    cout<<fibo(N);
    return 0;
}