#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
int N;
int answer = 1;
int arr[101][101];
int temp[101][101];
int mini=98765432,maxi=-1;
bool v[101][101];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
vector<pair<int,int> > t;
void bfs(int x,int y){
    queue<pair<int,int> > q;
    v[x][y] = true;
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<=0 || ny<=0 || nx>N || ny>N || v[nx][ny]) continue;
            v[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
            mini = min(mini,arr[i][j]);
            maxi = max(maxi,arr[i][j]);
        }
    }
    for(int i=mini;i<=maxi;++i){
        int cnt=0;
        t.clear();
        memset(v,false,sizeof(v));
        for(int j=1;j<=N;++j){
            for(int k=1;k<=N;++k){
                if(arr[j][k]<=i) v[j][k]=true;
                else t.push_back({j,k});
            }
        }
        for(int j=0;j<t.size();++j){
            if(v[t[j].first][t[j].second]) continue;
            bfs(t[j].first,t[j].second);
            cnt++;
        }
        answer = max(cnt,answer);
    }
    cout<<answer<<'\n';
    return 0;
}