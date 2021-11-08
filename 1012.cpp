#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int w,h,cabbage,N;
int dp[51][51];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    dp[x][y] = -1;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int n_x = cur_x + dx[i];
            int n_y = cur_y + dy[i];

            if(n_x < 0 || n_x >= w || n_y < 0 || n_y>=h || dp[n_x][n_y] == 0 || dp[n_x][n_y] == -1 ){
                continue;
            }
            dp[n_x][n_y] = -1;
            q.push(make_pair(n_x,n_y));
        }
    }
}
int main(){
    int a,b;
    cin>>N;
    for(int i=0;i<N;++i){
        int count=0;
        cin>>w>>h>>cabbage;
        for(int j=0;j<cabbage;++j){
            cin>>a>>b;
            dp[a][b] = 1;
        }
        for(int j=0;j<w;++j){
            for(int k=0;k<h;++k){
                if(dp[j][k]==1){
                    bfs(j,k);
                    count++;
                }
            }
        }
        cout<<count<<'\n';
    }
    
    return 0;
}