#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int F,S,G,U,D;
int v[1000001];
void elevator(int x){
    v[x] = 0;
    queue<int> q;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur==G){cout<<v[cur];return ;}
        for(int i=0;i<2;++i){
            int nx;
            if(i==0) nx = cur+U;
            else nx = cur-D;
            if(nx>F||v[nx]>0||nx<=0) continue;
            q.push(nx);
            v[nx] = v[cur]+1;
        }
    }
    cout<<"use the stairs";
}
int main(){
    cin>>F>>S>>G>>U>>D;
    elevator(S);
    return 0;
}