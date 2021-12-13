#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int N,M;
int answer=0;
vector<pair<int,int> > v;
int arr[10][10];
int temp[10][10];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void fill(int x,int y,int dir){//x,y좌표 및 방향에 따라서 채운다 이때, 방향은 비트 연산을 하여서 방향을 설정한다.
    dir%=4;
    while(1){
        x += dx[dir];
        y += dy[dir];
        if(x<=0 || y<=0 || x>N || y>M || temp[x][y]==6) return;
        if(temp[x][y]!=0) continue;
        temp[x][y] = 9;
    }
}
void search(){//위에서 구한 fill 함수를 통해서 방향이 4가지이므로 4진수를 이용해서 shift연산의 *2를 해서 4배씩 곱해지게 하여서 연산을 최소화 했다.
    for(int i=0;i<(1<<2*v.size());++i){
        memcpy(temp,arr,sizeof(arr));
        int point = i;
        for(int j=0;j<v.size();++j){
            int dir = point%4;
            point/=4;
            int x = v[j].first;
            int y = v[j].second;
            if(arr[x][y]==1){
                fill(x,y,dir);
            }
            else if(arr[x][y]==2){
                fill(x,y,dir);
                fill(x,y,dir+2);
            }
            else if(arr[x][y]==3){
                fill(x,y,dir);
                fill(x,y,dir+1);
            }
            else if(arr[x][y]==4){
                fill(x,y,dir);
                fill(x,y,dir+1);
                fill(x,y,dir+2);
            }
            else{
                fill(x,y,dir);
                fill(x,y,dir+1);
                fill(x,y,dir+2);
                fill(x,y,dir+3);
            }
            int val = 0;
            for(int k=1;k<=N;++k){
                for(int q=1;q<=M;++q){
                    if(temp[k][q]==0) val++;
                }
            }
            answer = min(answer,val);
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
            if(arr[i][j]!=0 && arr[i][j]!=6) v.push_back({i,j});
            if(arr[i][j]==0) answer++;
        }
    }
    search();//최소값을 답에 저장
    cout<<answer<<'\n';
    return 0;
}