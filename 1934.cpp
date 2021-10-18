#include <iostream>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int lcd(int a,int b){
    return a*b/(gcd(a,b));
}
int main(){
    int N,a,b;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        cout<<lcd(a,b)<<'\n';
    }
    return 0;
}