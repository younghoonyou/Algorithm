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
    for(int i=0;i<N;++i){
        if(k<=i){
            tmp[n] = arr[i];
            back(n+1,i);
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