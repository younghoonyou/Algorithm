#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N,L,R;//인접하는 차이가 L이상 R이하이다.
int arr[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
vector<int> v[51];
bool check(int x,int y){
    if(abs(x-y)>=L && abs(x-y)<=R) return true;
    return false;
}
void box(){
    queue<pair<int,int> > q;

}
int main(){
    cin>>N>>L>>R;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
        }
    }

    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
        }
    }
    return 0;
}