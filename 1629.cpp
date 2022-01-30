//https://www.acmicpc.net/problem/1629
#include<iostream>
using namespace std;
typedef long long ll;
ll a,b,c;
ll mul(ll d,ll e){
    if(e==0) return 1;
    else if(e==1) return d;
    if(e&1) return mul(d,e-1)*d;
    ll temp = mul(d,e/2);
    temp%=c;
    return (temp*temp)%c;
}
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>a>>b>>c;
    cout<<mul(a,b)%c;
    return 0;
}//분할 제곱 a^n = a^(n/2)*a^(n/2) 복잡도 O(logN)