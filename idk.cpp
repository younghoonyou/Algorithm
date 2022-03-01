#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <memory.h>
#include <set>
using namespace std;
int N,M,D;
int arr[17][16];
int temp[17][16];
bool v[16][16];
bool visit[16];
int order[4];
int answer = 0;
int tmp = 0;
struct Enemy{
    int x,y;
    bool kill;
};
vector<Enemy> enemy;
vector<Enemy> enemy_temp;
bool cmp(Enemy a,Enemy b){
    if(a.y==b.y) return a.x>b.x;
    return a.y<b.y;
}
int dist(int x,int y,int _x,int _y){
    return abs(x-_x) + abs(y-_y);
}
bool alive(){
    for(int i=0;i<enemy_temp.size();++i){
        if(!enemy_temp[i].kill) return true;
    }
    return false;
}
void attack(){
    set<int> index;
    for(int i=1;i<=3;++i){
        int x = N+1;
        int y = order[i];
        for(int j=0;j<enemy_temp.size();++j){
            if(enemy_temp[j].kill) continue;
            int cur_x = enemy_temp[j].x;
            int cur_y = enemy_temp[j].y;
            if(dist(cur_x,cur_y,x,y)>D) continue;
            // index.insert(j);
            enemy_temp[j].kill = true;
            temp[cur_x][cur_y] = 0;
            tmp++;
            break;
        }
    }
    // cout<<"---------attack----------\n";
    // for(int i=1;i<=N;++i){
    //     for(int j=1;j<=M;++j){
    //         cout<<temp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
    // for(auto i:index) enemy_temp[i].kill = true,tmp++;
    index.clear();
}

void enemy_move(){
    for(int i=1;i<=M;++i){
        for(int j=N-1;j>=0;--j){
            temp[j+1][i] = temp[j][i];
        }
    }
    for(int i=1;i<=M;++i){
        temp[1][i] = 0;
    }
    for(int i=0;i<enemy_temp.size();++i){
        if(enemy_temp[i].kill) continue;
        if((enemy_temp[i].x) + 1 == N+1){enemy_temp[i].kill = true;continue;}
        enemy_temp[i].x++;
    }
    // cout<<"---------move----------\n";
    // for(int i=1;i<=N;++i){
    //     for(int j=1;j<=M;++j){
    //         cout<<temp[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }
}

void fight(){
    while(alive()){
        attack();
        enemy_move();
    }
}
void archor(int n,int k){
    if(n==4){
        tmp = 0;
        enemy_temp = enemy;
        memcpy(temp,arr,sizeof(arr));
        fight();
        answer = max(answer,tmp);
        return ;
    }
    for(int i=k;i<=M;++i){
        if(visit[i]) continue;
        visit[i] = true;
        order[n] = i;
        archor(n+1,i);
        visit[i] = false;
    }
}
int main(){
    cin>>N>>M>>D;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
            if(arr[i][j]==1) enemy.push_back({i,j,false});
        }
    }
    sort(enemy.begin(),enemy.end(),cmp);
    archor(1,1);
    cout<<answer<<'\n';
    return 0;
}