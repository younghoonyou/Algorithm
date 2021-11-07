#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
using namespace std;
vector<int> dp[1001];
bool v[1001];
bool v2[1001];
void dfs(int start){
    stack<int> s;
    v[start] = true;
    s.push(start);
    cout<<start<<" ";//첫번째 출력 후 나머지 출력
    while(!s.empty()){
        int x = s.top();
        s.pop();
        for(int i=0;i<dp[x].size();++i){
            int y = dp[x][i];
            if(!v[y]){
                cout<<y<<" ";
                s.push(x);
                s.push(y);
                v[y] = true;
                break;
            }
        }
    }
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    v2[start] = true;
    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        for(int i=0;i<dp[x].size();++i){
            int y = dp[x][i];
            if(!v2[y]){
                q.push(y);
                v2[y] = true;
            }
        }
        q.pop();
    }
}
int main(){
    int N,num,start;
    int a,b;
    cin>>N>>num>>start;
    for(int i=1;i<=num;++i){
        cin>>a>>b;
        dp[a].push_back(b);
        dp[b].push_back(a);
    }
    for(int i=1;i<N;++i){
        sort(dp[i].begin(),dp[i].end());//순서대로 정렬해준다.
    }
    dfs(start);
    cout<<'\n';
    bfs(start);
    return 0;
}