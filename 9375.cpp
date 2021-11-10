#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int dp[10001];
bool cmp(pair<string,string> &a,pair<string,string> &b){
    return a.second<b.second;
}
int fact(int n){
    if(n==0||n==1){
        dp[n] = 1;
        return dp[n];
    }
    if(dp[n]){
        return dp[n];
    }
    return dp[n] = fact(n-1) * n;
}
int main(){
    map<string,int> m;
    int N,t;
    cin>>N;
    string name,type;
    for(int i=0;i<N;++i){
        int sum=1;
        cin>>t;
        for(int j=0;j<t;++j){
            cin>>name>>type;
            m[type]++;//이렇게 추가 할  수 있다.
        }
        for(auto i:m){
        sum*=(i.second+1);
    }
    sum--;
    cout<<sum<<'\n';
    m.clear();
    }
    return 0;
}//vector 사용하지말고 map을 사용하면 그룹화가 훨씬 편하다 auto로 지정해 줄 수 있는 것을 기억하자.