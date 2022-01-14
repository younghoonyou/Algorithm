#include <iostream>
using namespace std;
int coin[] = {500,100,50,10,5,1};
int N;
int main(){
    int cnt = 0;
    cin>>N;
    N = 1000-N;
    for(int i=0;i<6;++i){
        cnt+=N/coin[i];
        N%=coin[i];
    }
    cout<<cnt<<'\n';
    return 0;
}