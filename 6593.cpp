//https://www.acmicpc.net/problem/6593
#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <memory.h>
using namespace std;
int L,R,C;
char arr[30][30][30];
int v[30][30][30];
int start_x,start_y,start_h;
int end_x,end_y;
const int dx[] = {1,0,-1,0,0,0};
const int dy[] = {0,1,0,-1,0,0};
const int dh[] = {0,0,0,0,1,-1};
queue<tuple<int,int,int> > q;
void escape(int cur_x,int cur_y,int cur_h){
    q.push({cur_x,cur_y,cur_h});
    v[cur_x][cur_y][cur_h] = 1;
    while(!q.empty()){
        int x,y,h;
        tie(x,y,h) = q.front();
        q.pop();
        for(int i=0;i<6;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nh = h + dh[i];
            if(nx<0 || ny<0 || nh<0 || nx>=R || ny>=C || nh>=L || arr[nx][ny][nh]=='#' || v[nx][ny][nh]>0) continue;
            v[nx][ny][nh] = v[x][y][h] +1;
            q.push({nx,ny,nh});
        }
    }
}
int main(){
    while(1){
        cin>>L>>R>>C;
        memset(v,0,sizeof(v));
        memset(arr,0,sizeof(arr));
        if(L==0&&R==0&&C==0) break;
        for(int i=0;i<L;++i){
            for(int j=0;j<R;++j){
                for(int k=0;k<C;++k){
                    cin>>arr[j][k][i];
                    if(arr[j][k][i]=='S') start_x = j,start_y = k,start_h=i;
                    else if(arr[j][k][i]=='E') end_x = j,end_y = k;
                }
            }
        }
        escape(start_x,start_y,start_h);
        if(v[end_x][end_y][L-1]==0) cout<<"Trapped!"<<'\n';
    else cout<<"Escaped in "<<v[end_x][end_y][L-1]-1<<" minute(s)."<<'\n';
    while(!q.empty()) q.pop();
    }
    return 0;
}//dx,dy,dh까지 3차원으로 생각하기