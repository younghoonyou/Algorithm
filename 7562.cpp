#include <iostream>
#include <queue>
#include <memory>
using namespace std;
int size;
int start_x,start_y,end_x,end_y;
int dp[301][301];
bool v[301][301];
int dx[8] = {-2,-1,1,2,-2,-1,1,2};
int dy[8] = {1,2,2,1,-1,-2,-2,-1};
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    dp[x][y] = 1;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        if(cur_x==end_x&&cur_y==end_y){
            while(!q.empty()){
                q.pop();
            }
            break;
        }
        for(int i=0;i<8;++i){
            int n_x = cur_x + dx[i];
            int n_y = cur_y + dy[i];
            if(n_x<0||n_y<0||n_x>=size||n_y>=size||dp[n_x][n_y]==1){
                continue;
            }
            if(!v[n_x][n_y]){
                q.push(make_pair(n_x,n_y));
                dp[n_x][n_y] = dp[cur_x][cur_y]+1;   
                v[n_x][n_y] = true;
            }
        }
    }
}
int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        int count=0;
        cin>>size;
        cin>>start_x>>start_y;
        cin>>end_x>>end_y;
        bfs(start_x,start_y);
        cout<<dp[end_x][end_y]-1<<'\n';
        memset(dp,0,sizeof(dp));
        memset(v,0,sizeof(v));
    }
    return 0;
}