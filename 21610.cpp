#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int N,M;
int arr[51][51];
bool check[51][51];
int dx[8] = {0,-1,-1,-1,0,1,1,1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};
int answer=0;
vector<pair<int,int> > temp;
vector<pair<int,int> > arr_temp;
pair<int,int> where(int x,int y){
    if(x>N) x-=N;
    else if(x<=0) x+=N;
    if(y>N) y-=N;
    else if(y<=0) y+=N;
    return {x,y};
}

void magic(){
    for(int i=0;i<temp.size();++i){
        int x = temp[i].first;
        int y = temp[i].second;
        for(int j=1;j<8;j+=2){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx<=0||ny<=0||nx>N||ny>N) continue;
            if(arr[nx][ny]!=0) arr[x][y]++;

        }
    }
    arr_temp.clear();
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(!check[i][j]&&(arr[i][j]>1)) arr[i][j]-=2,arr_temp.push_back({i,j});
        }
    }
    temp.clear();
    memset(check,false,sizeof(check));
}

void move(int dir,int num){
    for(int q=0;q<arr_temp.size();++q){
        int x = arr_temp[q].first;
        int y = arr_temp[q].second;
    for(int i=0;i<num;++i){
        x += dx[dir];
        y += dy[dir];
        x = where(x,y).first;
        y = where(x,y).second;
    }
    arr[x][y]++;
    check[x][y] = true;
    temp.push_back({x,y});
    }
    magic();
}
int main(){
    int dir,num;
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
        }
    }
    arr_temp.push_back({N,1});
    arr_temp.push_back({N,2});
    arr_temp.push_back({N-1,1});
    arr_temp.push_back({N-1,2});
    for(int i=0;i<M;++i){
        cin>>dir>>num;
        move(dir-1,num);
    }

    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            answer+=arr[i][j];
        }
    }
    cout<<answer<<'\n';
    return 0;
}//차근차근 시뮬하면서 시도를 하였다.