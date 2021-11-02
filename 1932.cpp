#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int dp[501][501];
int temp = 0;
int arr[501][501];
int N;
int sum(int n){
    int total=0;
    for(int i=1;i<=n;++i){
        total+=n;
    }
    return total;
}
int main(){
    dp[0][0] = 0;
    int N;
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=i;++j){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=i;++j){
            if(i==j){
                dp[i][j] = dp[i-1][j-1] + arr[i][j];
            }
            else if(j==1){
                dp[i][j] = dp[i-1][j] + arr[i][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j-1] + arr[i][j],dp[i-1][j] + arr[i][j]);
            }
        }
    }
    for(int i=1;i<=N;++i){
        if(temp<dp[N][i]){
            temp = dp[N][i];
        }
    }
    cout<<temp;
    return 0;
}