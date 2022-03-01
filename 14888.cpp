#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[12];
int bu[4];
int maxi=0,mini=999;
bool check(int n){
    for(int i=0;i<4;++i){
        bu[i];
    }
}
void cal(int n){
    if(n==N){
        for(int i=0;i<N-1;++i){
            maxi = max(maxi,arr[i]);
            mini = min(mini,arr[i]);
        }
        return;
    }
    for(int i=0;i<N;++i){
        if(check[i]){
            cal(n+1);
        }
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    for(int i=0;i<4;++i){
        cin>>bu[i];
    }
    cal(0);
    cout<<maxi<<'\n'<<mini;
    return 0;
}