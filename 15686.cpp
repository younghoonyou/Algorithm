#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>
#include <cmath>
using namespace std;
int N,M,answer=99999998;
int arr[51][51];
int temp[51][51];
bool check[2501];
int order[2501];
vector<pair<int,int> > one;
vector<pair<int,int> > two;
int search(int x,int y){
    int tmp = 99999998;
    for(int i=0;i<two.size();++i){
        if(!check[i]) tmp = min(tmp,abs(x-two[i].first)+abs(y-two[i].second));
    }
    return tmp;
}

void chicken(int n,int k){
    if(n==two.size()-M+1){
        int tmp=0;
        memcpy(temp,arr,sizeof(arr));
        for(int i=0;i<one.size();++i){
            tmp+=search(one[i].first,one[i].second);
        }
        answer = min(answer,tmp);
        return ;
    }
    for(int i=0;i<two.size();++i){
        if(!check[i]&&i>k){
            check[i] = true;
            arr[two[i].first][two[i].second] = 0;
            chicken(n+1,i);
            arr[two[i].first][two[i].second] = 2;
            check[i] = false;
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cin>>arr[i][j];
            if(arr[i][j] == 2) two.push_back({i,j});
            else if(arr[i][j] == 1) one.push_back({i,j});
        }
    }
    if(two.empty()||one.empty()){cout<<0<<'\n';return 0;}
    chicken(1,-1);
    cout<<answer<<'\n';
    return 0;
}