#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int arr[8];
int tmp[8];
bool v[8];

void back(int n,int k){
    if(n==M){
        for(int i=0;i<M;++i){
            cout<<tmp[i]<<" ";
        }
        cout<<'\n';
        return ;
    }
    int vc = 0;
    for(int i=k;i<N;++i){
        if(i>=k&& arr[i]!=vc){
            v[i] = true;
            tmp[n] = arr[i];
            vc = tmp[n];
            back(n+1,i);
            v[i] = false;
        }
    }
}
int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    sort(arr,arr+N);
    back(0,0);
    return 0;
}