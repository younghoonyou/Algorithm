#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int H,W;
int dir = 0;
int answer = 0;
char arr[101][101];
int temp[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<pair<int,int> > v;
void mirror(){
    queue<pair<int,int> > q;
    temp[v[0].first][v[0].second] = 0;
    arr[v[0].first][v[0].second] = 'S';
    q.push({v[0].first,v[0].second});
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<=0 || ny<=0 || nx>H ||ny>W || arr[nx][ny] == '*' || arr[nx][ny] == 'V' || arr[nx][ny] == 'S') continue;

            arr[nx][ny] = 'V';
            q.push({nx,ny});
        }
    }
}

int main(){
    cin>>W>>H;
    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            cin>>arr[i][j];
            if(arr[i][j]=='C') v.push_back({i,j});
        }
    }
    mirror();
    cout<<'\n';
    for(int i=1;i<=H;++i){
        for(int j=1;j<=W;++j){
            cout<<temp[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<temp[v[1].first][v[1].second];
    return 0;
}