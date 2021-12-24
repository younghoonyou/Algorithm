#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int R,C,T;
int arr[51][51];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
vector<pair<int,int> > vaccum;
struct Dust{
    int x,y,dust_,cnt;
};
vector<Dust> dust;
void search(){
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            if(arr[i][j]>0) dust.push_back({i,j,arr[i][j]/5,0});
        }
    }
}
int answer(){
    int sum = 0;
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            sum+=arr[i][j];
        }
    }
    sum+=2;
    return sum;
}

void rotate(int start_x,int start_y,int end_x,int end_y){//시계
        int temp = arr[start_x][start_y];
        for(int i=start_x+1;i<=end_x;++i){//1번재 순환
            arr[i-1][start_y] = arr[i][start_y];
        }
        for(int i=start_y+1;i<=end_y;++i){//2번째 순환
            arr[end_x][i-1] = arr[end_x][i];
        }
        for(int i=end_x-1;i>=start_x;--i){//3번재 순환
            arr[i+1][end_y] = arr[i][end_y];
        }
        for(int i=end_y-1;i>=start_y+1;--i){//4번째 순환
            arr[start_x][i+1] = arr[start_x][i];
        }
        arr[start_x][start_y+1] = temp;
        arr[vaccum[1].first][1] = -1;
        arr[vaccum[1].first][2] = 0;
}

void reverse_rotate(int start_x,int start_y,int end_x,int end_y){//반시계
        int temp = arr[start_x][start_y];
        for(int i=start_y;i<=end_y-1;++i){//1번재 순환
            arr[start_x][i] = arr[start_x][i+1];
        }
        for(int i=start_x;i<=end_x-1;++i){//2번째 순환
            arr[i][end_y] = arr[i+1][end_y];
        }
        for(int i=end_y-1;i>=start_y;--i){//3번재 순환
            arr[end_x][i+1] = arr[end_x][i];
        }
        for(int i=end_x-1;i>=start_x+1;--i){//4번째 순환
            arr[i+1][start_y] = arr[i][start_y];
        }
        arr[start_x+1][start_y] = temp;
        arr[vaccum[0].first][1] = -1;
        arr[vaccum[0].first][2] = 0;
}


void machine(){
    search();
    vector<Dust> sum;
    for(int i=0;i<dust.size();++i){
        for(int j=0;j<4;++j){
            int nx = dust[i].x + dx[j];
            int ny = dust[i].y + dy[j];
            if(nx<=0 || ny<=0 || nx>R || ny>C || arr[nx][ny] == -1) continue;
            sum.push_back({nx,ny,dust[i].dust_,0});
            dust[i].cnt++;
        }
    }
    for(int i=0;i<sum.size();++i){
        arr[sum[i].x][sum[i].y]+=sum[i].dust_;
    }

    for(int i=0;i<dust.size();++i){
        arr[dust[i].x][dust[i].y]-=(dust[i].cnt * dust[i].dust_);
    }
    dust.clear();
    sum.clear();
}

void spread(){//0은 반시계 방향,1은 시계방향
    rotate(vaccum[1].first,1,R,C);
    reverse_rotate(1,1,vaccum[0].first,C);
}

void cycle(int n){
    for(int i=0;i<n;++i){
        machine();
        spread();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C>>T;
    for(int i=1;i<=R;++i){
        for(int j=1;j<=C;++j){
            cin>>arr[i][j];
            if(arr[i][j]==-1) vaccum.push_back({i,j});
        }
    }
    cycle(T);
    cout<<answer()<<'\n';
    return 0;
}//구현