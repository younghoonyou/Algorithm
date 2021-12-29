#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N,M;
char arr[1001][1001];
bool v[1001][1001];
int answer[1001][1001];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int jx,jy;
queue<pair<int,int> > q;
void bfs(){
    int cnt = 0;
    queue<pair<int,int> > j;
    j.push({jx,jy});
    while(!j.empty()){
        int tmp = q.size();
        for(int i=0;i<tmp;++i){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;++i){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<=0 || ny<=0 || nx>N || ny>M || arr[nx][ny]=='#' || arr[nx][ny]=='F') continue;
                arr[nx][ny] = 'F';
                q.push({nx,ny});
            }
        }
        tmp = j.size();
        for(int i=0;i<tmp;++i){
        int x = j.front().first;
        int y = j.front().second;
        j.pop();
        if(x==1||y==1||x==N||y==M){cout<<answer[x][y]+1<<'\n';return;}
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<=0 || ny<=0 || nx>N || ny>M || arr[nx][ny]=='#' || arr[nx][ny]=='F'||arr[nx][ny]=='J') continue;
            arr[nx][ny] = 'J';
            j.push({nx,ny});
            answer[nx][ny] = answer[x][y]+1;
            cnt = answer[nx][ny];
        }
        }
    }
    cout<<"IMPOSSIBLE"<<'\n';
    return ;
}
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int k=1;k<=M;++k){
            cin>>arr[i][k];
            if(arr[i][k]=='J') jx=i,jy=k;
            else if(arr[i][k]=='F')  q.push({i,k});
        }
    }
    bfs();
    return 0;
}