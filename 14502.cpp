#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
using namespace std;
int n,m;
int arr[9][9];
int temp[9][9];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int answer=-1;
queue<pair<int,int> > q;
void virus(){
    queue<pair<int,int> > temp_q = q;
    memcpy(temp,arr,sizeof(arr));
    while(!temp_q.empty()){
        int cur_x = temp_q.front().first;
        int cur_y = temp_q.front().second;
        temp_q.pop();
        for(int i=0;i<4;++i){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx<=0||ny<=0||nx>n||ny>m||temp[nx][ny]==1||temp[nx][ny]==2) continue;
            temp[nx][ny] = 2;
            temp_q.push({nx,ny});
        }
    }
}
int zero(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(temp[i][j]==0) cnt++;
        }
    }
    return cnt;
}
void wall(int N){
    if(N==4){
        virus();
        answer = max(answer,zero());
        return ;
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(arr[i][j]==0){
                arr[i][j] = 1;
                wall(N+1);
                arr[i][j] = 0;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>arr[i][j];
            if(arr[i][j]==2) q.push({i,j});
        }
    }
    wall(1);
    cout<<answer<<'\n';
    return 0;
}