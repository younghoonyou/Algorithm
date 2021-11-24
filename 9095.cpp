#include <iostream>
#include <algorithm>
using namespace std;
int N;
int dp[11];
int ans(int n){
    if(n==1){dp[n]=1;return dp[n];}
    if(n==2){dp[n]=2;return dp[n];}
    if(n==3){dp[n]=4;return dp[n];}
    if(dp[n]) return dp[n];
    return dp[n] = ans(n-1)+ans(n-2)+ans(n-3);
}
int main(){
    int temp;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        cout<<ans(temp)<<'\n';
    }
    return 0;
}