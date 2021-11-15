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
            last = 'A';
        }
        else if(dp[i]<temp[i]){
            b+=3;
            last = 'B';
        }
        else{
            a++;
            b++;
        }
    }
    cout<< a << " "<< b <<'\n';
        if(a>b){
            cout<<'A';
        }
        else if(a<b){ 
            cout<<'B';
        }
        else{
            cout<<last;
        }
    return 0;
}