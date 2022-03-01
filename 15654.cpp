#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
int arr[8];
int tmp[8];
bool v[8];
void back(int n){
    if(n==M){
        for(int i=0;i<M;++i){
            cout<<tmp[i]<<" ";
        }
        cout<<'\n';
    }
    for(int i=0;i<N;++i){
        if(!v[i]){
            v[i] = true;
            tmp[n] = arr[i];
            back(n+1);
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
    back(0);
    return 0;
}