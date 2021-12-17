#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int N,M,K;
int r,c,s;
int answer=987654321;
int arr[51][51];
int temp_arr[51][51];
bool visit[7];
int rcs[3][7];
int order[7];
vector<int> soon;
void rotate(int start_x,int start_y,int end_x,int end_y){
        int temp = temp_arr[start_x][start_y];
        for(int i=start_x+1;i<=end_x;++i){//1번재 순환
            temp_arr[i-1][start_y] = temp_arr[i][start_y];
        }
        for(int i=start_y+1;i<=end_y;++i){//2번째 순환
            temp_arr[end_x][i-1] = temp_arr[end_x][i];
        }
        for(int i=end_x-1;i>=start_x;--i){//3번재 순환
            temp_arr[i+1][end_y] = temp_arr[i][end_y];
        }
        for(int i=end_y-1;i>=start_y+1;--i){//4번째 순환
            temp_arr[start_x][i+1] = temp_arr[start_x][i];
        }
        temp_arr[start_x][start_y+1] = temp;
}

void change(int r,int c,int s){
    for(int d=1;d<=s;++d){
    int start_x = r-d;
    int start_y = c-d;
    int end_x = r+d;
    int end_y = c+d;
        rotate(start_x,start_y,end_x,end_y);
    }
}

void array_rotate(int n){
    if(n==K+1){
        memcpy(temp_arr,arr,sizeof(arr));
        for(int i=1;i<=K;++i){
            change(rcs[0][order[i]],rcs[1][order[i]],rcs[2][order[i]]);
        }
        for(int i=1;i<=N;++i){
            int sum=0;
            for(int j=1;j<=M;++j){
                sum+=temp_arr[i][j];
            }
            answer = min(answer,sum);
        }
        return;
    }
    for(int i=1;i<=K;++i){
        if(!visit[i]){
            visit[i] = true;
            order[n] = i;
            array_rotate(n+1);
            visit[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("Text.txt", "r", stdin);
    cin>>N>>M>>K;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<=K;++i){
        cin>>r>>c>>s;
        rcs[0][i] = r;
        rcs[1][i] = c;
        rcs[2][i] = s;
    }
    array_rotate(1);
    cout<<answer<<'\n';
    return 0;
}