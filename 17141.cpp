//https://www.acmicpc.net/problem/17141
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
int N,M;
int one = 0;
int num = 0;
int arr[50][50];
int temp[50][50];
bool v[50][50];
bool v_tmp[10];
int order_x[10];
int order_y[10];
int answer=987654321;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
vector<pair<int,int> > vi;
queue<pair<int,int> > t;
int bfs(){
    int tmp = 0;
    while(!t.empty()){
        int x = t.front().first;
        int y = t.front().second;
        t.pop();
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || ny<0 || nx>=N || ny>=N || v[nx][ny]||arr[nx][ny]==1) continue;
            v[nx][ny] = true;
            temp[nx][ny] = temp[x][y]+1;
            tmp = max(temp[nx][ny],tmp);
            t.push({nx,ny});
            num++;
        }
    }
    return tmp;
}
void virus(int n,int k){
    if(n==M){
        num = 0;
        memset(temp,0,sizeof(temp));
        memset(v,0,sizeof(v));
        while(!t.empty()) t.pop();
        for(int i=0;i<M;++i){
            t.push({order_x[i],order_y[i]});
            v[order_x[i]][order_y[i]] = true;
        }
        int tmp = bfs();
        if(N*N - one - M !=num) return ;
        answer = min(answer,tmp);
        return ;
    }
    for(int i=k;i<vi.size();++i){
        int x = vi[i].first;
        int y = vi[i].second;
        if(v_tmp[i]) continue;
        v_tmp[i] = true;
        order_x[n] = x;
        order_y[n] = y;
        virus(n+1,i);
        v_tmp[i] = false;
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
            if(arr[i][j]==2) vi.push_back({i,j});
            else if(arr[i][j]==1) one++;
        }
    }
    virus(0,0);
    if(answer==987654321) cout<<-1<<'\n';
    else cout<<answer<<'\n';
    return 0;
}//천천히 문제 분석하면서