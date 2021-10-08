#include <iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    long long a,b,v;
    long day;
    cin>> a >> b >> v;
    if((v-a)%(a-b)==0){
        day = (v-a)/(a-b)+1;
    }
    else{
        day = (v-a)/(a-b)+2;
    }
    cout<<day<<'\n';
    return 0;
}