#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
int N;
int arr[100][100];
int v[100][100][2];
bool visit[100][100];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
vector<pair<int,int> > map;

int dis(int x,int y,int _x,int _y){
    return abs(x - _x) + abs(y - _y);
}
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push({x,y});
    visit[x][y] = true;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        for(int i=0;i<4;++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<0 || ny<0 || nx>=N ||ny>=N ||visit[nx][ny]) continue;
            visit[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
            if(arr[i][j]==1) map.push_back({i,j}),visit[i][j] = true;
        }
    }
    for(int i=0;i<map.size();++i){
        int x = map[i].first;
        int y = map[i].second;
        if(visit[x][y]) continue;
        bfs(x,y);
    }
    return 0;
}
