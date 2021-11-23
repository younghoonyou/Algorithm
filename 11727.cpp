#include <iostream>
using namespace std;
typedef long long ll;
ll dp[1001];
ll tile(int n){
    if(n==1){dp[n]=1; return dp[n];}
    if(n==2){dp[n]=3; return dp[n];}
    if(dp[n]) return dp[n];
    return dp[n] = (tile(n-1) + 2*tile(n-2))%10007;
}
int main(){
    int N;
    cin>>N;
    cout<<tile(N);
}