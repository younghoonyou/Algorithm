#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1001]={1,1,1,};
long long fibonacci(long long n){
    if(dp[n]){
        return dp[n];
    }
    if(n==1||n==2||n==3){
        dp[n] = 1;
        return dp[n];
    }
    else{
        return dp[n] = fibonacci(n-3)+fibonacci(n-2);
    }
}
int main(){
    long long N,k;
    cin>>k;
    for(int i=0;i<k;++i){
        cin>>N;
        cout<<fibonacci(N)<<'\n';
    }
    return 0;
}