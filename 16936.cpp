#include <iostream>
#include <algorithm>
using namespace std;
long long dp[1001];
long long tw(long long n){
    int count=0;
    while(n!=0){
        if(n%2!=0){
            return count;
        }
        n/=2;
        count++;
    }
    return count-1;
}
long long thr(long long n){
    int count=0;
    while(n!=0){
        if(n%3!=0){
            return count;
        }
        n/=3;
        count++;
    }
    return count-1;
}
bool cmp(long long a,long long b){
    if(thr(a)==thr(b)){
        return tw(a)<tw(b);
    }
    return thr(a)>thr(b);
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>dp[i];
    }
    sort(dp,dp+N,cmp);
    for(int i=0;i<N;++i){
        cout<<dp[i]<<" ";
    }
    return 0;
}