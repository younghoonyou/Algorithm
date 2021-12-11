#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int N,K;
int recur(int i,int j){
    if(dp[i][j]) return dp[i][j];
    if(i==j||j==0){
      dp[i][j] = 1;
      return dp[i][j];
    }
    return dp[i][j] = recur(i-1,j-1)%10007 + recur(i-1,j)%10007;
}
int main(){
    cin>>N>>K;
    cout<<recur(N,K)%10007<<'\n';
    return 0;
}//파스칼로 이항계수를 표현 할 수 있다. 점화식 도출이 핵심