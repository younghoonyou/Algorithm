#include <iostream>
#include <algorithm>
#include <memory>
using namespace std;
int N;
int answer=0;
int arr[21][21];
int temp[21][21];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
void trans(int dir){
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            
        }
    }
}
void squre(int n){
    if(n==6){
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                answer = max(answer,arr[i][j]);
            }
        }
        return;
    }
    for(int i=0;i<4;++i){
        memcpy(temp,arr,sizeof(arr));
        
    }
}
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
        }
    }
    return 0;
}