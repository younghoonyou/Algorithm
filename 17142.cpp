#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
vector<pair<int,int> > virus;
bool v[51];
int N,M;
int arr[51][51];
int temp[51][51];
int answer=9876;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int zero_num = 0;
queue<pair<int,int> > q;
void find(){
    int virus_num=0;
    int total=0;
    while(!q.empty()){
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(nx>=0&&ny>=0&&nx<N&&ny<N){
                if(arr[nx][ny]!=1&&temp[nx][ny]==-1){
                    temp[nx][ny] = temp[cur_x][cur_y] + 1;
                    if(arr[nx][ny]==0){
                        virus_num++;
                        total = temp[nx][ny];
                    }
                    q.push({nx,ny});
                }
            }
        }
    }
    if(virus_num==zero_num){
        answer = min(answer,total);
    }
}
void select(int n,int k){
    if(n==M){
        memset(temp,-1,sizeof(temp));
        while(!q.empty()) q.pop();
        for(int i=0;i<virus.size();++i){
            if(v[i]){
                q.push({virus[i].first,virus[i].second});
                temp[virus[i].first][virus[i].second] = 0;
            }
        }
        find();
        return ;
    }
    for(int i=0;i<virus.size();++i){
        if(i>k&&!v[i]){
            v[i] = true;
            select(n+1,i);
            v[i] = false;
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
            if(arr[i][j]==2) virus.push_back({i,j});
            if(arr[i][j]==0) zero_num++;
        }
    }
    select(0,-1);
    if(answer==9876){ cout<<-1<<'\n';return 0;}
    cout<<answer<<'\n';
    return 0;
}//각각의 함수를 만들어주는 것은 잘했다, 하지만 || 대신에 확실한 &&을 통해서 bfs를 풀어가자
//그리고 시간에 따른 temp 변수를 하나 만들어줘서 arr값에 의해서 계산만 하는 temp도 좋은 시도였다.