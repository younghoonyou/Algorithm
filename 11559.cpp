//https://www.acmicpc.net/problem/11559
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
char arr[12][6];
bool v[12][6];
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
queue<pair<int,int> > color;
vector<pair<int,int> > make_blank;
int answer = 0;
bool infinity = false;
bool check(int x,int y){
    make_blank.clear();
    int num=1;
    char stand = arr[x][y];
    queue<pair<int,int> > q;
    q.push({x,y});
    v[x][y]=false;
    make_blank.push_back({x,y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<0 || ny<0 ||nx>=12 ||ny>=6 || arr[nx][ny]!=stand || !v[nx][ny]) continue;
            v[nx][ny] = false;
            q.push({nx,ny});
            make_blank.push_back({nx,ny});
            num++;
        }
    }
    if(num>=4){infinity = true; return true;}
    else return false;
}

void move(){
    bool flag = false;
    for(int i=11;i>=0;--i){
        for(int j=0;j<6;++j){
            v[i][j] = false;
            if(arr[i][j]!='.'){
                int x = i+1;
                if(x==12){v[x-1][j]=true;color.push({x-1,j});continue;}
                while(x<12){
                    if(arr[x][j]!='.') break;
                    x++;
                }
                color.push({x-1,j});
                v[x-1][j] = true;
                if(x-1==i) continue;
                arr[x-1][j] = arr[i][j];
                arr[i][j]='.';
            }
        }
    }
}

void puyo(){
    while(1){
    infinity =false;
    move();
    while(!color.empty()){
        int x = color.front().first;
        int y = color.front().second;
        color.pop();
        if(!v[x][y]) continue;
        if(check(x,y)){
            for(int j=0;j<make_blank.size();++j){
                arr[make_blank[j].first][make_blank[j].second]='.';
            }
        }
    }
    if(!infinity) break;
    answer++;
    }
}
int main(){
    for(int i=0;i<12;++i){
        string str;
        cin>>str;
        for(int j=0;j<6;++j){
            arr[i][j]=str[j];
        }
    }
    puyo();
    cout<<answer<<'\n';
    return 0;
}//침착하게 잘 생각했다. 시도를 많이 했다.