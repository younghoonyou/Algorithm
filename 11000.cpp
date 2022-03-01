#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,start,end,temp=99;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> room;
    cin>>N;
    for(int i=0;i<N;++i){
        cin >> start >> end;
        room.push(make_pair(start,end));
    }
    cout<<room.top().first<<" "<<room.top().second<<endl;

    return 0;

}