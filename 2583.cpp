#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int arr[101][101];
int N,M,K;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> v;
void find(int x,int y){
    queue<pair<int,int> > q;
    int cnt=1;
    arr[x][y] = 1;
    q.push({x,y});
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx<1||ny<1||nx>M||ny>N||arr[nx][ny]==1){
                continue;
            }
            q.push({nx,ny});
            arr[nx][ny] = 1;
            cnt++;
        }
    }
    v.push_back(cnt);
}
int main(){
    cin>>N>>M>>K;
    int x_bot,y_bot;
    int x_top,y_top;
    for(int i=0;i<K;++i){
        cin>>x_bot>>y_bot>>x_top>>y_top;
        for(int j=x_bot+1;j<=x_top;j++){
            for(int k=y_bot+1;k<=y_top;k++){
                if(arr[j][k]) continue;
                arr[j][k] = 1;
            }
        }
    }
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(arr[j][i]==0) find(j,i);
        }
    }
    cout<<v.size()<<'\n';
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();++i){
        cout<<v[i]<<" ";
    }
    return 0;
}