#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long yaksu(int n){
    long long sum=0;
    for(int i=1;i<=n;++i){
        long long temp = n / i;
        temp *= i;
        sum += temp;
    }
        return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin>>N;
    cout<<yaksu(N);
    return 0;
}//초기화 시키는거 잊지말자 제발..