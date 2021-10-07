#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.second==b.second){return a.first<b.first;}
    return a.second<b.second;
}
int main(){
    int N,x,y;
    vector<pair<int,int> > temp;
    cin>>N;
    for(int i=0;i<N;++i){
        cin >> x >> y;
        temp.push_back(make_pair(x,y));
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<N;++i){
        cout<< temp[i].first << " " << temp[i].second <<'\n';
    }
    return 0;
}