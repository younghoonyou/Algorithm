#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int W,H;
int cheeze_num = 0;
int v[101][101];
int dx[4] = {1,-1,-0,0};
int dy[4] = {0,0,1,-1};
queue<pair<int,int> > q;
int count_num(){
    int count=0;
    for(int i=0;i<W;++i){
        for(int j=0;j<H;++j){
            if(v[i][j]==1) count++;
        }
    }
    return count;
}
// void make_ch(int x,int y){
//     queue<pair<int,int> > temp;
//     temp.push({x,y});
//     v[x][y] = 2;
//     while(!temp.empty()){
//         int cur_x = temp.front().first;
//         int cur_y = temp.front().second;
//         temp.pop();
//         for(int i=0;i<4;++i){
//             int nx = cur_x + dx[i];
//             int ny = cur_y + dy[i];
//             if(nx<0||ny<0||nx>=W||ny>=H||v[nx][ny]==1||v[nx][ny]==8) continue;            
//             temp.push({nx,ny});
//             v[nx][ny] = 8;
//         }
//     }
// }
// void cheeze(){
//     while(!q.empty()){
//         int cur_x = q.front().first;
//         int cur_y = q.front().second;
//         q.pop();
//         for(int i=0;i<4;++i){
//             int nx = cur_x + dx[i];
//             int ny = cur_y + dy[i];
//             if(nx<0||ny<0||nx>=W||ny>=H||v[nx][ny]==8) continue;
//             q.push({nx,ny});
//             v[nx][ny] = 8;
//         }
//     }
// }
void check(){
    for(int i=0;i<W;++i){//왼쪽
        for(int j=0;j<H;++j){
            if(v[i][j]==2) break;
            if(v[i][j]==1){
                v[i][j] = 2;
                break;
            }

        }
    }
    for(int i=0;i<H;++i){//오른쪽
        for(int j=W-1;j>=0;--j){
            if(v[i][j]==2) break;
            if(v[i][j]==1){
                v[i][j] = 2;
                break;
            }
        }
    }
    for(int i=W-1;i>=0;--i){//아래
        for(int j=H-1;j>=0;--j){
            if(v[j][i]==2) break;
            if(v[j][i]==1){
                v[j][i] = 2;
                break;
            }
        }
    }
    for(int i=0;i<W;++i){//위
        for(int j=0;j<H;++j){
            if(v[j][i]==2) break;
            if(v[j][i]==1){
                v[j][i] = 2;
                break;
            }
        }
    }
}
int main(){
    cin>>W>>H;
    for(int i=0;i<W;++i){
        for(int j=0;j<H;++j){
            cin>>v[i][j];
            if(v[i][j]==1) cheeze_num++;
        }
    }
    // make_ch(0,0);
    check();
    // cout<<count_num();
    // cheeze();
    cout<<'\n';
    for(int i=0;i<W;++i){
        for(int j=0;j<H;++j){
            cout<<v[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<count_num();
    return 0;
}