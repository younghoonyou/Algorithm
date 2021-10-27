#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int N;
int count;
int recur(int n){
    if(dp[n]){
        return dp[n];
    }
    if(n==1){
        return 0;
    }
    if(n==2||n==3){
        return 1;
    }
    if(n%6==0){
        return dp[n] = min(recur(n/3)+1,recur(n/2)+1);
    }
    if(n%3==0){
            return dp[n] = min(recur(n/3)+1,recur(n-1)+1);
    }
    if(n%2==0){
            return dp[n] = min(recur(n/2)+1,recur(n-1)+1);
    }
        return dp[n] = recur(n-1)+1;
}
int main(){
    cin>>N;
    cout<<recur(N);
    return 0;
}