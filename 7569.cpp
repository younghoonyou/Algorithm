#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int dp[101][101][101];
int N,M,H;
int dx[6] = {1,-1,-0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<pair<pair<int,int>,int> >q;
void tomato(void){
    while(!q.empty()){
        int cur_x = q.front().first.first;
        int cur_y = q.front().first.second;
        int cur_z = q.front().second;
        q.pop();
        for(int i=0;i<6;++i){
           int nx = cur_x + dx[i];
           int ny = cur_y + dy[i];
           int nz = cur_z + dz[i];
           if(nx<0||ny<0||nz<0||nx>=N||ny>=M||nz>=H||dp[nx][ny][nz]==-1||dp[nx][ny][nz]>=1){
               continue;
           }
           dp[nx][ny][nz] = dp[cur_x][cur_y][cur_z] + 1;
           q.push({{nx,ny},nz});
        }
    }
}
int main(){
    int maxi=0;
    cin>>N>>M>>H;
    for(int i=0;i<H;++i){
        for(int j=0;j<M;++j){
            for(int k=0;k<N;++k){
                cin>>dp[k][j][i];
                if(dp[k][j][i]==1){
                    q.push({{k,j},i});
                }
            }
        }
    }
    tomato();
    for(int i=0;i<H;++i){
        for(int j=0;j<M;++j){
            for(int k=0;k<N;++k){
                if(maxi<dp[k][j][i]){
                    maxi = dp[k][j][i];
                }
                if(dp[k][j][i]==0){
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<maxi-1;
    return 0;
}