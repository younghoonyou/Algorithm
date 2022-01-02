#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <memory.h>
using namespace std;
char arr[5][5];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
bool v[5][5];
int answer = 0;
int order_x[7];
int order_y[7];
vector<pair<int,int> > s;
bool check(){
    int tmp=0;
    for(int i=0;i<7;++i){
        if(arr[order_x[i]][order_y[i]]=='S') tmp++;
    }
    if(tmp<4) return false;
    return true;
}
bool bfs(){
    int num = 0;
    queue<pair<int,int> > q;
    int x = order_x[0];
    int y = order_y[0];
    q.push({x,y});
    v[x][y]=false;
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<0 || ny<0 || nx>=5 || ny>=5 || !v[nx][ny]) continue;
        if(v[nx][ny]){v[nx][ny]=false;num++;q.push({nx,ny});break;}
        }
    }
    if(num==7) return true;
    else return false;
}
void seven(int n,int k){
    if(n==7){
        if(check()){
            if(bfs()) answer++;
            else return ;
        }
        else return ;
    }
    for(int i=k;i<s.size();++i){
        int x = s[i].first;
        int y = s[i].second;
        if(v[x][y]) continue;
        v[x][y] = true;
        order_x[n] = x;
        order_y[n] = y;
        seven(n+1,k);
        v[x][y] = false;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for(int i=0;i<5;++i){
        string str;
        cin>>str;
        for(int j=0;j<5;++j){
            arr[i][j]=str[j];
            s.push_back({i,j});
        }
    }
    seven(0,0);
    cout<<answer<<'\n';
    return 0;
}