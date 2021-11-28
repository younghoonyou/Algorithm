#include <iostream>
using namespace std;
int a[8];
int main(){
    for(int i=0;i<8;++i){
        cin>>a[i];
    }
    if(a[0]>a[1]){
        for(int i=1;i<8;++i){
            if(a[i-1]-1 != a[i]){
                cout<<"mixed";   
                return 0;             
            }
        }
        cout<<"descending";
    }
    else if(a[0]<a[1]){
        for(int i=1;i<8;++i){
            if(a[i-1]+1 != a[i]){
                cout<<"mixed";                
                return 0;
            }
        }
        cout<<"ascending";
    }
    else{
        cout<<"mixed";
    }
    return 0;
}

