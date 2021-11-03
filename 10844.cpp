#include <iostream>
#include <algorithm>
using namespace std;
long long dp[101][10];
int main(){
    long long N;
    long long total=0;
    cin>>N;
    for(int i=1;i<=9;++i){
        dp[1][i] = 1;
    }
    for(int i=2;i<=N;++i){
        for(int j=0;j<=9;++j){
            if(j==0){
                dp[i][j] = dp[i-1][1];
                continue;
            }
            else if(j==9){
                dp[i][j] = dp[i-1][8];
                continue;
            }
            dp[i][j] = (dp[i-1][j+1] + dp[i-1][j-1])%1000000000;
        }
    }
    for(int i=0;i<=9;++i){
        total+=dp[N][i];
    }
    cout<<total%1000000000;
    return 0;
}