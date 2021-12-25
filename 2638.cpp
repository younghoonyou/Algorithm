#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N,M,T=0;
int arr[101][101];
bool v[101][101];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
queue<pair<int,int> > q;
bool compare(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(arr[i][j]==1) return true;
        }
    }
    return false;
}
void make_two(){
    queue<pair<int,int> > tw;
    tw.push({1,1});
    arr[1][1] = 2;
    while(!tw.empty()){
        int curx = tw.front().first;
        int cury = tw.front().second;
        tw.pop();
        for(int i=0;i<4;++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<=0||ny<=0||nx>N||ny>M||arr[nx][ny]>0) continue;
            arr[nx][ny] = 2;
            tw.push({nx,ny});
        }
    }
}
void search(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(arr[i][j]==2) continue;
            else if(arr[i][j]==1){
                int cnt = 0;
                int x = i;
                int y = j;
                for(int k=0;k<4;++k){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(arr[nx][ny]==2) cnt++;
                }
                if(cnt>=2) q.push({x,y});
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        arr[x][y] = 2;
    }
    T++;
}
// void cheeze(){
//     vector<pair<int,int> > ch;
//     while(!q.empty()){
//         int x = q.front().first;
//         int y = q.front().second;
//         int cnt = 0;
//         q.pop();
//         for(int i=0;i<4;++i){
//             int nx = x + dx[i];
//             int ny = y + dy[i];
//             if(nx<=0 || ny<=0 || nx>N || ny>M) continue;
//             if(arr[nx][ny] == 0) cnt++;
//         }
//         if(cnt>1) ch.push_back({x,y});
//     }
//     for(int i=0;i<ch.size();++i){
//         arr[ch[i].first][ch[i].second] = 0;
//     }
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
            if(arr[i][j]==1) q.push({i,j});
        }
    }
    while(compare()){
        make_two();
        search();
    }
    cout<<T<<'\n';
    return 0;
}