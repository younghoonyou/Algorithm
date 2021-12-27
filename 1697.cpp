#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int start,END;
bool v[2*MAX];
int find(int n,int k){
    queue<pair<int,int> > q;
    v[n] = true;
    q.push({n,k});
    while(!q.empty()){
        int line = q.front().first;
        int time = q.front().second;
        q.pop();
        if(line == END) return time;
        int a = line+1,b = line-1,c = line*2;
        if(a>=0&&a<2*MAX && !v[a]) v[a] = true,q.push({a,time+1});
        if(b>=0&&b<2*MAX && !v[b]) v[b] = true,q.push({b,time+1});
        if(c>=0&&c<2*MAX && !v[c]) v[c] = true,q.push({c,time+1});
    }
    return -1;
}
int main(){
    cin>>start>>END;
    cout<<find(start,0);
    return 0;
}