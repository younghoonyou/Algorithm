#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int answer = 0;
int arr[501][501];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
bool v[501][501];
int x_order[501];
int y_order[501];

void tetorimi(int x,int y,int n){
    if(n==4){
        int tmp = 0;
        for(int i=0;i<4;++i){
            tmp+=arr[x_order[i]][y_order[i]];
        }
        answer = max(answer,tmp);
        return ;
    }
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=N || ny>=M || v[nx][ny]) continue;
        v[nx][ny] = true;
        x_order[n] = nx;
        y_order[n] = ny;
        tetorimi(nx,ny,n+1);
        v[nx][ny] = false;
    }
    if(x-1 >= 0 && y-1 >= 0 && x+1 < N) { //ㅓ
        answer = max(answer, (arr[x-1][y] + arr[x][y-1] + arr[x][y] + arr[x+1][y]));
    }
    if(x-1 >= 0 && y+1 < M && x+1 < N) { //ㅏ
        answer = max(answer, (arr[x-1][y] + arr[x][y+1] + arr[x][y] + arr[x+1][y]));
    }
    if(y-1 >= 0 && y+1 < M && x+1 < N) { //ㅗ
        answer = max(answer, (arr[x][y] + arr[x+1][y] + arr[x+1][y-1] + arr[x+1][y+1]));
    }
    if(y-1 >= 0 && y+1 < M && x+1 < N) { //ㅜ
        answer = max(answer, (arr[x][y-1] + arr[x][y] + arr[x][y+1] + arr[x+1][y]));
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            v[i][j] = true;
            tetorimi(i,j,0);
            v[i][j] = false;
        }
    }
    cout<<answer<<'\n';
    return 0;
}