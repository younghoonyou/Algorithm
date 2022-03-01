#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N,M;
int start_x,start_y,start_direction;
int direction[4] = {0,1,2,3};//북동남서
int dx[4] = {0,-1,0,1};//북,동,남,서
int dy[4] = {-1,0,1,0};//방향을 기준으로 진행방향은 서,북,동,남
int arr[51][51];
queue<pair<int,int> > q;
int robot(int x,int y,int z){
    int cur_direction = z-1;
    if(arr[x][y]==1) return 0;
    q.push({x,y});
    int answer=1;
    arr[x][y] = 1;
    while(!q.empty()){
        int flag = 0;
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();
        for(int i=0;i<4;++i){
            if(cur_direction>3) cur_direction-=4;
            if(cur_direction<0) cur_direction+=4;
            int nx = cur_x + dx[cur_direction];
            int ny = cur_y + dy[cur_direction];
            if(nx<0||ny<0||nx>=N||ny>=M||arr[nx][ny]>=1){cur_direction++;flag++;continue;}
            // cur_direction--;
            arr[nx][ny] = arr[cur_x][cur_y]+1;
            q.push({nx,ny});
            answer++;
            break;
            }
            if(flag==4){
            int temp = cur_direction;
            temp--;
            if(temp<0) temp+=4;
            int nnx = cur_x + dx[direction[temp]];
            int nny = cur_y + dy[direction[temp]];
            if(nnx<0||nny<0||nnx>=N||nny>=M||arr[nnx][nny]==1||arr[nnx][nny]>1) break;
            q.push({nnx,nny});
            answer++;
            }
    }
    return answer;
}
int main(){
    cin>>N>>M;
    cin>>start_x>>start_y>>start_direction;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>arr[i][j];
        }
    }
    cout<<robot(start_x,start_y,start_direction)<<'\n';
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    return 0;
}