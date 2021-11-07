#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> dp[101];
bool v[101];
void bfs(int start){
    queue<int> q;
    v[start] = true;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        if(v[x]){
            for(int i=0;i<dp[x].size();++i){
                int y = dp[x][i];
                if(!v[y]){
                    v[y] = true;
                    q.push(y);
                }
            }
        }
        q.pop();
    } 
}
int main(){
    int N,line;
    int a,b,count=0;
    cin>>N;
    cin>>line;
    for(int i=0;i<line;++i){
        cin>>a>>b;
        dp[a].push_back(b);
        dp[b].push_back(a);
    }
    bfs(1);
    for(int i=1;i<=N;++i){
        if(!v[i]){
            count++;
        }
    }
    cout<<N-count-1;//나머지 연결 안된 부분 세기
    return 0;
}