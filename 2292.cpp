#include <iostream>
using namespace std;
int main(){
    int N,count=0,temp;
    cin>>N;
    temp=1;
    if(N==1){
        cout<<1<<endl;
        return 0;
    }
    while(N>temp){
        temp+=count*6;
        count++;
    }
    cout<<count<<endl;
}