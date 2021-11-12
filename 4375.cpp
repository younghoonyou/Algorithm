#include <iostream>
using namespace std;
int main(){
    long long N;
    while((cin>>N)){
    long long count=1,t=1,sum=0;
    while(t<=N){
        t*=10;
    }
    long long b = t%N;
    while(1){
        sum+=b;
        b = (10*b)%N;
        if(sum%N==0){
            break;
        }
        count++;
    }
    cout<<count<<'\n';
    count=1;
    }
    return 0;
}//수학적으로 접근하자 그리고 문제좀 잘 읽자