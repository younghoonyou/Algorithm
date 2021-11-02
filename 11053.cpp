#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int arr[1001];
int main(){
    int N,count=1;
    int maxi,temp=0;
    dp[0] = 0;
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
    }
    for(int i=1;i<=N;++i){
        dp[i] = 1;
        for(int j=1;j<=i;++j){
            if(arr[j]<arr[i]){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        temp = max(temp,dp[i]);
    }
    cout<<temp;
    return 0;
}