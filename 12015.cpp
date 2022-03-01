#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
bool gong[1000001];
int main(){
    int N,m;
    cin>>N>>m;
    for(int i=0;i<N;++i){
        cin>>dp[i];
    }
    sort(dp,dp+N);
    gong[dp[0]] = true;
    gong[dp[N-1]] = true;
    for(int i=0;i<N;++i){
        int start = 0;
        int end = N-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(dp[mid]>dp[i]){
                end = mid - 1;
            }
            else if(dp[mid]<dp[i]){
                start = mid + 1;
            }
            else{
                gong[i] = true;
            }
        }
    }
    return 0;
}