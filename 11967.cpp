#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int arr[100][100];
bool v[100][100];
bool light_v[100][100];
vector<pair<int,int> > light[100][100];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int N,M;
int answer=1;
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push({x,y});
    v[x][y] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int t=0;t<light[x][y].size();++t){
            int curx = light[x][y][t].first;
            int cury = light[x][y][t].second;
            if(light_v[curx][cury]) continue;
            light_v[curx][cury] = true;
        }
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<=0 || ny<=0 ||nx>N || ny>N || !light_v[nx][ny]) continue;
            q.push({nx,ny});
        }
    }
}
int main(){
    int x,y,a,b;
    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>x>>y>>a>>b;
        light[x][y].push_back({a,b});
        // light[a][b].push_back({x,y});
    }
    bfs(1,1);
    cout<<answer<<'\n';
    return 0;
}