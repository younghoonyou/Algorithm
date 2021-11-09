#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;
int N,M;
int dp[1001][1001];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int> > q;
void bfs(void){
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx<0||ny<0||nx>=N||ny>=M||dp[nx][ny]==-1||dp[nx][ny]>=1){
                continue;
            }
                dp[nx][ny] = dp[cur_x][cur_y]+1;
                q.push(make_pair(nx,ny));
        }
    }
}
int main(){
    int a,maxi=0,cnt=0,mini=-3;
    cin>>N>>M;
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            cin>>dp[j][i];
            if(dp[j][i]==1){
                q.push(make_pair(j,i));
            }
        }
    }
    bfs();
    for(int i=0;i<M;++i){
        for(int j=0;j<N;++j){
            if(maxi<dp[j][i]){
                maxi = dp[j][i];
            }
            if(dp[j][i]==0){
                cout<<-1;
                return 0;
            }
        }
    }
    cout<<maxi-1;
    return 0;
}//2개 이상 1이 있음을 고려해서 넣고 시작 (큐의 특성이 여기서 나온다.)