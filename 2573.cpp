#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
int N,M;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
bool v[301][301];
int arr[301][301];
vector<pair<int,int> > temp;
int num(int x,int y){
    int tmp = 0;
    for(int i=0;i<4;++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<=0 || ny<=0 || nx>N || ny>M) continue;
        if(arr[nx][ny]==0) tmp++;
    }
    return tmp;
}

void bfs(int x, int y){
    queue<pair<int,int> > q;
    q.push({x,y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            int nx = curx + dx[i];
            int ny = cury + dy[i];
            if(nx<=0 || ny<=0 || nx>N || ny>M || !v[nx][ny]) continue;
            v[nx][ny] = false;
            q.push({nx,ny});
        }
    }
}
int ice_num(){
    int num = 0;
    int  tmp = temp.size();
    for(int i=0;i<tmp;++i){
        int x = temp[i].first;
        int y = temp[i].second;
        if(v[x][y]){
            bfs(x,y);
            num++;
        }
    }
    return num;
}
void hoon(){
    vector<tuple<int,int,int> > plu;
    vector<pair<int,int> > temper;
    int tmp = temp.size();
    for(int i=0;i<tmp;++i){
        int x = temp[i].first;
        int y = temp[i].second;
        if(arr[x][y]-num(x,y)<0) plu.push_back({x,y,0});//저장한 다음에 반영
        else plu.push_back({x,y,arr[x][y]-num(x,y)});
        // if(arr[x][y]!=0) plu.push_back({x,y}),v[x][y]=true;
    }
    int tmp2 = plu.size();
    int x,y,val;
    for(int i=0;i<tmp2;++i){
        tie(x,y,val) = plu[i];
        arr[x][y] = val;
        if(arr[x][y]!=0) temper.push_back({x,y}),v[x][y]=true;
    }
    temp.clear();
    temp = temper;
    plu.clear();
    temper.clear();
}


int main(){
    int ans = 0;
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
            if(arr[i][j]!=0) temp.push_back({i,j}),v[i][j]=true;
        }
    }
    while(1){
        int tp = ice_num();
        if(tp>1) break;
        if(temp.size()==0){ans=0;break;}
        hoon();
        ans++;
    }
    cout<<ans<<'\n';
    return 0;
}