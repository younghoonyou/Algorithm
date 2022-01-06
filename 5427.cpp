#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
int N,w,h;
char arr[1000][1000];
bool v[1000][1000];
int answer[1000][1000];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int start_x,start_y;
queue<pair<int,int> > fire;
void escape(int x,int y){
    queue<pair<int,int> > sang;
    sang.push({x,y});
    answer[x][y] = 1;
    v[x][y] = true;
    while(!sang.empty()){
        int tmp = fire.size();
        for(int i=0;i<tmp;++i){
            int fx = fire.front().first;
            int fy = fire.front().second;
            fire.pop();
            for(int j=0;j<4;++j){
                int nfx = fx + dx[j];
                int nfy = fy + dy[j];
                if(nfx<0 || nfy<0 || nfx>=h ||nfy>=w ||arr[nfx][nfy]=='#'||arr[nfx][nfy]=='*') continue;
                fire.push({nfx,nfy});
                arr[nfx][nfy]='*';
            }
        }
        int tp = sang.size();
        for(int s=0;s<tp;++s){
        int curx = sang.front().first;
        int cury = sang.front().second;
        sang.pop();
        if(curx==0||cury==0||curx==h-1||cury==w-1){cout<<answer[curx][cury]<<'\n';return ;}
        for(int i=0;i<4;++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<0 || ny<0 || nx>=h ||ny>=w || arr[nx][ny]=='#' || arr[nx][ny]=='*'||v[nx][ny]) continue;
            answer[nx][ny] = answer[curx][cury] + 1;
            v[nx][ny] = true;
            sang.push({nx,ny});
        }
        }
    }
    cout<<"IMPOSSIBLE"<<'\n';
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;++i){
        memset(arr,0,sizeof(arr));
        memset(v,false,sizeof(v));
        memset(answer,0,sizeof(answer));
        while(!fire.empty()) fire.pop();
        cin>>w>>h;
        for(int j=0;j<h;++j){
            for(int k=0;k<w;++k){
                cin>>arr[j][k];
                if(arr[j][k]=='@') start_x = j,start_y = k;
                else if(arr[j][k]=='*') fire.push({j,k});
            }
        }
        escape(start_x,start_y);
    }
    return 0;
}