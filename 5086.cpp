#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a,b;
    while(1){
        cin>>a>>b;
        if(!(a|b)){
            return 0;
        }
        if(b>a&&b%a==0){
            cout<<"factor"<<'\n';
        }
        else if(a>b&&a%b==0){
            cout<<"multiple"<<'\n';
        }
        else{
            cout<<"neither"<<'\n';
        }
    }
    return 0;
}