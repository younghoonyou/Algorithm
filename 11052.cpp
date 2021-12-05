#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001]={0,};
int dp[1001]={0,};
int N;
void card(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=i;++j){
            dp[i] = max(dp[i],dp[i-j] + arr[j]);
        }
    }
    cout<<dp[N];
}
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
    }
    card();
    return 0;
}//DP문제는 순차적으로 생각해서 알고리즘을 짜야한다.