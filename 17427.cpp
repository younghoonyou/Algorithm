#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    long long sum=0;
    cin>>n;
    for(int i=1;i<=n;++i){
        long long temp = n / i;
        temp *= i;
        sum += temp;
    }
    cout<<sum;
    return 0;
}