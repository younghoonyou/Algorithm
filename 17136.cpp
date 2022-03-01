#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue<pair<int,int> > q;
int arr[11][11];
int box[6];
int squre(int x,int y){
    int n = 1;
    while(1){
    for(int i = x;i<=x+n;++i){
        for(int j = y;j<=y+n;++j){
            if(arr[i][j]==0) return n;
        }
    }
    if(n==5) break;
    n++;
    }
    return n;
}
void num(int n){
    if(n==11){
        
        return ;
    }
    for(int i=0;i<5;++i){

    }
}
int main(){
    for(int i=1;i<=10;++i){
        for(int j=1;j<=10;++j){
            cin>>arr[i][j];
            if(arr[i][j]==1) q.push({i,j});
        }
    }
    cout<<squre(2,3);
    return 0;
}