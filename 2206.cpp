#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <tuple>
#define NUM 1001
using namespace std;
int N,M,x,y,block;
int arr[NUM][NUM];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int visit[NUM][NUM][2] = {0,};
queue<tuple<int,int,int> > q;
string str;
int dfs(){
    q.push({0,0,0});
    visit[0][0][0] = 1;
    while(!q.empty()){
        tie(x,y,block) = q.front();//tie를 쓰므로 하나씩 선언을 안해줘도 된다
        q.pop();
        if(x == N-1 && y == M-1) return visit[N-1][M-1][block];
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=M) continue;
            if(visit[nx][ny][block]) continue;
            if(arr[nx][ny] == 0) visit[nx][ny][block] = visit[x][y][block] + 1 , q.push({nx,ny,block});
            else if(arr[nx][ny] == 1){
                if(block == 1) continue;
                visit[nx][ny][block+1] = visit[x][y][block] + 1;
                q.push({nx,ny,block+1});
            }
        }
    }
    return -1;
}
int main(){
    scanf("%d %d",&N,&M);
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            scanf("%1d",&arr[i][j]);//1d를 선언하므로 하나씩 인자들을 가져올 수 있다
        }
    }
    printf("%d\n",dfs());
    return 0;
}//visit에서 3차원 배열을 사용하면서 뚫었을 때와 안 뚫었을 때를 구분해서 생각한다