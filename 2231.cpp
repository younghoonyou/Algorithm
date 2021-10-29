#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int length(int n){
    int count=0;
    while(n/10!=0){
        n/=10;
        count++;
    }
    return count;
}
int dp[7];
void result(int n){
    int count=length(n)+1;
    int temp = n;
    while(count--){
        dp[count] = temp%10;
        temp/=10;
    }
}
int main(){
    int N,total=0,mini=1000001,condi=0;
    cin>>N;
    int temp = N;
    while(temp--){
        total=0;
        condi=0;
        result(temp);
        for(int i=0;i<=length(temp);++i){
            total += dp[i]*pow(10,length(temp)-i)+dp[i];
            condi += dp[i]*pow(10,length(temp)-i);
        }
        if(total==N&&mini>condi){
            mini = min(mini,condi);
        }
    }
    if(mini==1000001){
        mini=0;
    }
    cout<<mini;
    return 0;
}