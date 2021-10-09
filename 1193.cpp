#include <iostream>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,count=1,total=0;
    cin>>N;
    while(total<N){
        total+=count;
        count++;
    }
    if(count%2){
        cout<<count-(total-N+1)<<"/"<<total-N+1;
    }
    else{
        cout<<total-N+1<<"/"<<count-(total-N+1);
    }
    return 0;
}