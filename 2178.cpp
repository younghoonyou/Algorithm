#include <iostream>
#include <queue>
#include <string>
using namespace std;
int dp[101][101];
bool v[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int n,m;
void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    dp[x][y] = 1;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        if(cur_x==n&&cur_y==m){
            while(!q.empty()){
                q.pop();
            }
            break;
        }
        for(int i=0;i<4;++i){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx<0||ny<0||nx>=n||ny>=m||dp[nx][ny]==0){
               continue; 
            }
            if(!v[nx][ny]){
                dp[nx][ny] = dp[cur_x][cur_y] + 1;
                v[nx][ny] = true;
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main(){
    int a;
    string str;
    cin>>n>>m;
    for(int i=0;i<n;++i){
        cin>>str;
        for(int j=0;j<str.length();++j){
            dp[i][j] = str[j] - '0';
        }
    }
    bfs(0,0);
    cout<<dp[n-1][m-1];
    return 0;
}