#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[100001];
bool visit[100001];
int answer[100001];
void tree(int n){
    queue<int> q;
    visit[n] = true;
    q.push(n);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<v[x].size();++i){
            int y = v[x][i];
            if(!visit[y]){
                visit[y] = true;
                q.push(y);
                answer[y] = x;
            }
        }
    }
}
int main(){
    int N,a,b;
    cin>>N;
    for(int i=0;i<N-1;++i){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    tree(1);
    for(int i=2;i<=N;++i){
         cout<<answer[i]<<'\n';
    }
    return 0;
}