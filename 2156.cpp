#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001];
int arr[10001];
int maxi=0;
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
    }
    dp[1] = arr[1];
    dp[2] = arr[1]+arr[2];
    dp[3] = max(arr[1]+arr[3],max(dp[2],arr[2]+arr[3]));
    for(int i=4;i<=N;++i){
        dp[i] = max(dp[i-2]+arr[i],max(dp[i-1],dp[i-3]+arr[i-1]+arr[i]));
    }
    for(int i=1;i<=N;++i){
        if(maxi<dp[i]){
            maxi = dp[i];
        }
    }
    cout<<maxi;
    return 0;
}