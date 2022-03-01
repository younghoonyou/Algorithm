#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int size = 2;
int eat = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int arr[21][21];
int start_x,start_y;
vector<pair<int,int> > fish;
queue<pair<int,int> > q;

void search(int n){//n개 보다 작을 때 배열에 추가
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(arr[i][j]<n) fish.push_back({i,j});
        }
    }   
}

void go(){
    search(size);
    int x = start_x;
    int y = start_y;
    q.push({x,y});
    while(!q.empty()){
        q.pop();
        for(int i=0;i<4;++i){
            int nx = x + dx[i];
            int ny = y + dy[i];
        }
    }
}

int main(){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
            if(arr[i][j]==9) start_x = i,start_y = j;
        }
    }
    return 0;
}