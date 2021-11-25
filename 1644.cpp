#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll N;
vector<ll> temp;
bool v[4000001]={true,true,};
void sosu(ll n){
    for(ll i=2;i<=n;++i){
        if(v[i]) continue;
        temp.push_back(i);
        for(ll j=i*2;j<=n;j+=i){
            v[j] = true;
        }
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll count=0;
    cin>>N;
    sosu(N);
    if(temp.empty()){
        cout<<0;
        return 0;
    }
    ll start=0,end=0;
    ll sum = temp[start];
    while(end<=temp.size()&&start<=end){
        if(sum>=N){
            if(sum==N) count++;
            sum -= temp[start];
            start++;
        }
        else{
            end++;
            sum+=temp[end];
        }
    }
    cout<<count<<'\n';
    return 0;
}