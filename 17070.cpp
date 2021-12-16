#include <iostream>
#include <algorithm>
using namespace std;
int N;
int cnt=0;
int arr[17][17];
int dx[3] = {0,1,1};//→, ↘, ↓   i=0 -> 0,1    i=1 -> 0,1,2  i=2 -> 1,2
int dy[3] = {1,1,0};//→, ↘, ↓
void pipe(int x,int y,int num){
    if(x==N && y==N){
        cnt++;
        return;
    }
        for(int i=0;i<3;++i){
            if(num==0&&i==2) continue;
            if(num==2&&i==0) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(arr[nx][ny]>0 || nx<=0 || ny<=0 || nx>N || ny>N) continue;
            if(i==1){
                if(arr[nx-1][ny]>0 || arr[nx][ny-1]>0) continue;
            }
            arr[nx][ny] = 2;
            pipe(nx,ny,i);
            arr[nx][ny] = 0;
        }
}
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
        }
    }
    arr[1][1] = 2;
    arr[1][2] = 2;
    pipe(1,2,0);
    cout<<cnt;
    return 0;
}//백트래킹 + BFS로 간단히 풀었다 문제를 잘 읽자