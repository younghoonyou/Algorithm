#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N;
char arr[101][101];
bool v[101][101];
bool iv[101][101];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

void inormal(int x,int y){
    bool flag = false;
    queue<pair<int,int> > q;
    iv[x][y] = true;
    q.push({x,y});
    char stand = arr[x][y];
    if(stand=='R' || stand=='G') flag = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<=0 || ny<=0 || nx>N || ny>N ||iv[nx][ny]) continue;
            if(flag&&arr[nx][ny]=='B') continue;
            else if(!flag&&arr[nx][ny]!=stand) continue;
            iv[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

void normal(int x,int y){
    queue<pair<int,int> > q;
    v[x][y] = true;
    q.push({x,y});
    char stand = arr[x][y];
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<=0 || ny<=0 || nx>N || ny>N || v[nx][ny] || arr[nx][ny]!=stand) continue;
            v[nx][ny] = true;
            q.push({nx,ny});
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
        }
    }
    int nor=0,inor=0;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(!v[i][j]) normal(i,j),nor++;
            if(!iv[i][j]) inormal(i,j),inor++;
        }
    }
    cout<<nor<<'\n';
    cout<<inor<<'\n';
    return 0;
}