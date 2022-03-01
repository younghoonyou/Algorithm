#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N,n,m;
int arr[200][200];
bool v[200][200];
const int hdx[] = {-1,-2,-2,-1,1,2,2,1};
const int hdy[] = {-2,-1,1,2,2,1,-1,-2};
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
void monkey(){
    queue<pair<int,int> > q;
    q.push({0,0});
    v[0][0] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        for(int i=0;i<8;++i){
            int nx = x + hdx[i];
            int ny = y + hdy[i];
            if(nx<0 || ny<0 || nx>=n || ny>=m || v[nx][ny]) continue;
            v[nx][ny] = true;
            q.push({nx,ny});

        }
    }
}
int main(){
    cin>>N;
    cin>>n>>m>>;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>arr[i][j];
        }
    }
    monkey();
    return 0;
}