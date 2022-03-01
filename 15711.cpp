#include <iostream>
#include <algorithm>
#include <cmath>
#define maxi 2000000
using namespace std;
bool arr[2000001]={true,true,};

void sosu(){
    for(long long i=2;i<=maxi;++i){
        if(!arr[i]){
            for(long long j=i*2;j<=maxi;j+=i){
                arr[j] = true;
            }
        }
    }
}
int main(){
    sosu();
    long long N,a,b;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        long long temp = a+b;
        for(int i=2;i<=temp;++i){
            if(!arr[i]&&!arr[temp-i]){
                cout<<"YES"<<'\n';
                break;
            }
            if(i==temp) cout<<"NO"<<'\n';
        }
    }
    return 0;
}