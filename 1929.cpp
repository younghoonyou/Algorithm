#include <iostream>
#include <vector>
using namespace std;
long arr[1000001];
void sosu(long N,long M){
    for(int i=0;i<=M;++i){
        if(arr[i]){
            continue;
        }
        for(int j=2*i;j<=M;j=j+i){
            arr[j]++;
        }
    }
    for(int i=N;i<=M;i++){
        if(!arr[i]){
            cout<<i<<'\n';
        }
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    arr[0]=1;
    arr[1]=1;
    long mini,maxi;
    cin >> mini >> maxi;
    sosu(mini,maxi);
    return 0;
}