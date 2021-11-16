#include <iostream>
#include <algorithm>
using namespace std;
int N,M;
bool v[12];
int arr[12];
void answer(int n){
    if(n==M){
        for(int i=0;i<M;++i){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1;i<=N;++i){
        if(!v[i]&&arr[n-1]<i){
            v[i] = true;
            arr[n] = i;
            answer(n+1);
            v[i] = false;
        }
    }
}
int main(){
    cin>>N>>M;
    answer(0);
    return 0;
}