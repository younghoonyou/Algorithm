#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int>&a,pair<int,int>&b){
    if(a.first==b.first){
        return a.second<b.second;
    }
    return a.first<b.first;
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    int N,x,y;
    cin >> N;
    vector<pair<int,int> > temp;
    for(int i=0;i<N;++i){
        cin >> x >> y;
        temp.push_back(make_pair(x,y));
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<N;++i){
        cout << temp[i].first << " " << temp[i].second << '\n';
    }
    return 0;
}