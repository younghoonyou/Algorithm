#include <iostream>
#include <algorithm>
using namespace std;
int temp[1001];
int main(){
    int N,final,total=0;
    bool flag1=false,flag2=false;
    cin>>N>>final;
    for(int i=0;i<N;++i){
        cin>>temp[i];
    }
    sort(temp,temp+N);
    for(int i=0;i<N-2;++i){
        for(int j=i+1;j<N-1;++j){
            for(int k=j+1;k<N;++k){
                if(temp[i]+temp[j]+temp[k]<=final){
                    total=max(temp[i]+temp[j]+temp[k],total);
                }
                }
            }
        }
    cout<<total;
    return 0;
}