#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001];
int arr[100001];
int main(){
    int N,maxi;
    dp[0] = 0;
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
    }
        for(int j=1;j<=N;++j){
            dp[j] = dp[j-1] + arr[j];
            if(dp[j]<arr[j]){
                dp[j] = arr[j];
            }
        }
    maxi = dp[1];
        for(int i=2;i<=N;++i){
            if(maxi<dp[i]){
                maxi = dp[i];
            }
        }
    cout<<maxi;
    return 0;
}