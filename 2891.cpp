#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N,S,R;
    int s_temp,r_temp;
    int count=0;
    cin>>N>>S>>R;
    vector<int> dp(N+1,1);
    for(int i=0;i<S;++i){
        cin>>s_temp;
        dp[s_temp]--;
    }
    for(int i=0;i<R;++i){
        cin>>r_temp;
        dp[r_temp]++;
    }
    for(int i=1;i<=N;++i){
        if(dp[i]==0){
            if(dp[i-1]==2){
                dp[i]++;
                dp[i-1]--;
            }
            else if(dp[i+1]==2){
                dp[i]++;
                dp[i+1]--;
            }
        }
    }
    for(int i=1;i<=N;++i){
        if(dp[i]==0){
            count++;            
        }
    }
    cout<<count;
    return 0;
}