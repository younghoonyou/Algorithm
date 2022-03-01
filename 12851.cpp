#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int N,M;
int answer;
bool v[2*MAX];
int cnt = 1;
void dfs(int n,int k){
    queue<pair<int,int> > q;
    q.push({n,k});
    v[n] = true;
    while(!q.empty()){
        int line = q.front().first;
        int time = q.front().second;
        q.pop();
        if(line==M) answer = time,cnt++;
        int a=line-1,b=line+1,c=line*2;
        if(a>=0&&a<2*MAX&&!v[a]) v[a] = true,q.push({a,time+1});
        if(b>=0&&b<2*MAX&&!v[b]) v[b] = true,q.push({b,time+1});
        if(c>=0&&c<2*MAX&&!v[c]) v[c] = true,q.push({c,time+1});
        v[M] = false;
    }
}
int main(){
    cin>>N>>M;
    dfs(N,0);
    cout<<answer<<'\n';
    cout<<cnt<<'\n';
    return 0;
}