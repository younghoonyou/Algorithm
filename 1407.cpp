#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a,b,answer;
ll f(ll n){
    ll r = n;
    for(ll i=2;i<=n;i*=2){
        r+=(n/i)*(i/2);
    }
    return r;
}//F(n) = ∑(2^k-1)*(n/2^k)	k=0 ~ ∞ 공식을 알아야한다
int main(){
    ll sum = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>a>>b;
    cout<<f(b) - f(a-1);
    return 0;
}