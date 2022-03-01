#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
int map[101][101];
vector<pair<int,char> > Move;
int N,snake_change,apple_num;
int direction = 0;
void play(){
    int cnt = 0;
    deque<pair<int,int> > q;
    q.push_back({1,1});
    for(int i=0;i<snake_change;++i){
        int go = Move[i].first;
        for(int j=0;j<go;++j){
            int x = q.front().first;
            int y = q.front().second;
            int tmp = q.size();
            map[x][y] = 2;
            for(int k=0;k<tmp;++k){
                int nx = x + dx[direction];
                int ny = y + dy[direction];
                if(nx>N || ny>N || nx<=0 || ny<=0 || map[nx][ny]==2){cout<<cnt<<'\n';return ;}
                map[nx][ny] = 2;
            }
            // int x = q.front().first;
            // int y = q.front().second;
            // cout<<x<<" "<<y<<'\n';
            // map[x][y] = 2;
            // int nx = x + dx[direction];
            // int ny = y + dy[direction];
            // cnt++;
            // if(nx>N || ny>N || nx<=0 || ny<=0 || map[nx][ny]==2){cout<<cnt<<'\n';return ;}
            // q.push_front({nx,ny});
            // if(map[nx][ny]==1){map[nx][ny]=2;continue;}
            // map[nx][ny] = 2;
            // q.pop_back();
            // map[x][y] = 0;
        }
        direction = Move[i].second;
        if(direction=='D') direction = (direction+1)%4;
        else if(direction=='L'){
            direction--;
            if(direction<0) direction+=4;
        }
    }
}
int main(){
    cin>>N;
    cin>>apple_num;
    for(int i=0;i<apple_num;++i){
        int apple_x,apple_y;
        cin>>apple_x>>apple_y;
        map[apple_x][apple_y] = 1;
    }
    cin>>snake_change;
    for(int i=0;i<snake_change;++i){
        int second;
        char dir;
        cin>>second>>dir;
        Move.push_back({second,dir});
    }
    play();
    return 0;
}