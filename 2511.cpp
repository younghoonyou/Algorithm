#include <iostream>
using namespace std;
int dp[10];
int temp[10];
    int a=0,b=0;
    int index=-1;
    char last = 'D';
int main(){
    for(int i=0;i<10;++i){
        cin>>dp[i];
    }
    for(int i=0;i<10;++i){
        cin>>temp[i];
    }
    for(int i=0;i<10;++i){
        if(dp[i]>temp[i]){
            a+=3;
            last = 'A'
        }
        else if(dp[i]<temp[i]){
            b+=3;
            last = 'B'
        }
        else{
            a+=1;
            b+=1;
        }
    }
    cout<<a<<" "<<b<<'\n';
        if(dp[index]>temp[index]){
            cout<<'A';
        }
        else if(dp[index]<temp[index]){ 
            cout<<'B';
        }
        else{
            cout<<last;
        }
    return 0;
}