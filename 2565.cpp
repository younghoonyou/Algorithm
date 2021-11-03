#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    return a.first<b.first;
}
int dp[501];
vector<pair<int,int> > temp;
int main(){
    int N,a,b,maxi=0;
    cin>>N;
    for(int i=0;i<N;++i){        
            cin>>a>>b;
            temp.push_back(make_pair(a,b));
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<N;++i){
        dp[i] = 1;
        for(int j=0;j<i;++j){
            if(temp[j].second<temp[i].second){
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        maxi = max(maxi,dp[i]);
    }
    cout<<N-maxi;
    return 0;
}