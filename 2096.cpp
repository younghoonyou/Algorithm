#include <iostream>
#include <algorithm>
using namespace std;
int arr[100][3];
int N;
int dp[100][3];
int play(int n,int k){
    if(n==0){
        if(k==0) return max(arr[n][k],arr[n][k+1]);
        else if(k==1) return max(arr[n][k-1],max(arr[n][k],arr[n][k+1]));
        else if(k==2) return max(arr[n][k-1],arr[n][k]);
    }
    if(k==0) return dp[n][k] = max(arr[n][k]+play(n-1,k),arr[n][k]+play(n-1,k+1));
    else if(k==1) return dp[n][k] = max(arr[n][k]+play(n-1,k),max(arr[n][k]+play(n,k),arr[n][k]+play(n-1,k+1)));
    else if(k==2) return dp[n][k] = max(arr[n][k]+play(n-1,k),arr[n][k]+play(n-1,k-1));
    return 0;
}
int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<3;++j){
            cin>>arr[i][j];
        }
    }
    cout<<play(N-1,0);
    return 0;
}