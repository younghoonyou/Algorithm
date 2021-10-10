#include <iostream>
using namespace std;
int han(int N){
    int answer=0;
    for(int i=1;i<=N;++i){
        if(i<100||i%10+i/100==i/10%10*2){
        answer++;
        }
    }
    return answer;
}
int main(){
    int N;
    cin>>N;
    cout<<han(N);
    return 0;
}