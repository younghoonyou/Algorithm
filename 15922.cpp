#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(pair<int,int>&a, pair<int,int>&b){
if(a.first==b.first){
    return a.second<b.second;
}
return a.first<b.first;
}
int main(){
    int N,x,y,start,end;
    int total=0;
    cin>>N;
    vector<pair<int,int> > temp(N);
    for(int i=0;i<N;++i){
        cin >> x >> y;
        temp[i] = make_pair(x,y);
    }
    sort(temp.begin(),temp.end(),cmp);
    start = temp[0].first;
    end = temp[0].second;
    for(int i=1;i<N;++i){ 
        if(end>temp[i].first){
            end = max(end,temp[i].second);
        }
        else{
            total+=end - start ;
            start = temp[i].first;
            end = temp[i].second;
        }
    }
    total+= end - start;
    cout<<total<<endl;
    return 0;
}