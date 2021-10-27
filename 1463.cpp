#include <iostream>
#include <algorithm>
using namespace std;
int dp[1000001];
int N;
int count;
int recur(int n){
    if(!dp[n]){
        return dp[n];
    }
    if(n==1){
        return count;
    }
    if(n%3==0){
        n/=3;
        count++;
        return dp[n] = recur(n);
    }
    else if(n%2==0){
        n/=2;
        count++;
        return dp[n] = recur(n);
    }
    else{
        n-=1;
        count++;
        return dp[n] = recur(n);
    }
}
int main(){
    cin>>N;
    cout<<recur(N);
    return 0;
}