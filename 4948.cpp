#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long  N=1;
    long long count=0;
    long long arr[1000001]={};
    arr[0]=1;
    arr[1]=1;
    for(long long i=2;i<=1000001;++i){
        if(arr[i]){
            continue;
        }
        for(long long j=2*i;j<=1000001;j+=i){
            arr[j]++;
        }
    }
    while(1){
        cin>>N;
        if(N==0){
            break;
        }
        for(long long  i=N+1;i<=2*N;++i){
            if(!arr[i]){
                count++;
            }
        }
        cout<<count<<'\n';
        count=0;
    }
    return 0;
}