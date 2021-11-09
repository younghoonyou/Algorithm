#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
int size;
int answer[1001];
int dp[50][50];
bool v[50][50];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int bfs(int x,int y){
    int count=1;
    queue<pair<int,int> > q;
    q.push(make_pair(x,y));
    dp[x][y] = -1;
    v[x][y] = true;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx<0||ny<0||nx>=size||ny>=size||dp[nx][ny]==0||dp[nx][ny]==-1){
                continue;
            }
            if(!v[nx][ny]){
                dp[nx][ny] = -1;
                v[nx][ny] = true;
                q.push(make_pair(nx,ny));
                count++;
            }
        }
    }
    return count;
}
int main(){
    string str;
    int cnt=0;
    cin>>size;
    for(int i=0;i<size;++i){
        cin>>str;
        for(int j=0;j<str.size();++j){
            dp[i][j] = str[j]-'0';
        }
    }
    for(int i=0;i<size;++i){
        for(int j=0;j<size;++j){
            if(dp[i][j]==1){
                answer[cnt] = bfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<'\n';
    sort(answer,answer+cnt);
    for(int i=0;i<cnt;++i){
        if(answer[i]){
            cout<<answer[i]<<'\n';
        }
    }
    return 0;
}