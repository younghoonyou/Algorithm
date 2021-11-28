#include <iostream>
#define mod 1234567891
using namespace std;
int main(){
    long long N;
    long long R=1;
    long long sum=0;
    char temp;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        sum+=((temp-'a'+1)*R)%mod;
        R=(R*31)%mod;
    }
    cout<<sum%mod<<'\n';
    return 0;
}