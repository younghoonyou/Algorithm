#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int N,start,end;
    double n,a;
    cin>>N;
    for(int i=0;i<N;++i){
        int count=0;
        cin>>start>>end;
        end-=start;
        start=0;
        n = (int)sqrt(end);
        a = end - n*n;
        count = 2*n - 1;
        count+=ceil(a/n);
        cout<<count<<'\n';
    }
    return 0;
}