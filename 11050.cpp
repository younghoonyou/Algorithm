#include <iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    return fact(n-1)*n;
}
int main(){
    int a,b,total=1;
    cin>>a>>b;
    if(b==0||a==b){
        cout<<1;
        return 0;
    }
    for(int i=0;i<b;++i){
        total*=a;
        a--;
    }
    cout<<total/fact(b);
    return 0;
}