#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N,M;
int answer = 0;
int cnt=0;
int arr[501][501];
bool v[501][501];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
vector<pair<int,int> > t;

int bfs(int x,int y){
    int tmp=1;
    arr[x][y] = 1;
    queue<pair<int,int> > q;
    q.push({x,y});
    v[x][y] = true;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<=0 || ny<=0 || nx>N || ny>M || v[nx][ny]) continue;
            v[nx][ny] = true;
            arr[nx][ny] = arr[x][y] + 1;
            q.push({nx,ny});
            tmp++;
        }
    }
    return tmp;
}
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
            if(arr[i][j]==1) t.push_back({i,j});
            else v[i][j] = true;
        }
    }
    for(int i=0;i<t.size();++i){
        if(v[t[i].first][t[i].second]) continue;
        answer = max(answer,bfs(t[i].first,t[i].second));
        cnt++;
    }
    cout<<cnt<<'\n'<<answer<<'\n';
    return 0;
}