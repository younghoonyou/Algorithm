#include <iostream>
using namespace std;
int N,M,dis,cnt=0;
char arr[6][6];
int start_x,start_y;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
void home(int x,int y,int n){
    if(n==dis&&x==1&&y==M){
        cnt++;
        return ;
    }
    arr[x][y] = 'P';
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<=0 || ny<=0 || nx>N || ny>M || arr[nx][ny]=='T' || arr[nx][ny]=='P') continue;
        arr[nx][ny] = 'P';
        home(nx,ny,n+1);
        arr[nx][ny] = '.';
    }
}
int main(){
    cin>>N>>M>>dis;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
        }
    }
    start_x = N;
    start_y = 1;
    home(start_x,start_y,1);
    cout<<cnt<<'\n';
    return 0;
}