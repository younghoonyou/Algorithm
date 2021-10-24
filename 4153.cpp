#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int s,h,w;
    int maxi;
    while(1){
    cin>>s>>h>>w;
    if(s==0&&h==0&&w==0){
        return 0;
    }
    maxi = max(max(s,w),h);
    if(maxi==s){
        if(pow(maxi,2)==w*w+h*h){
            cout<<"right"<<'\n';
        }
        else{
            cout<<"wrong"<<'\n';
        }
    }
    else if(maxi==w){
        if(pow(maxi,2)==s*s+h*h){
            cout<<"right"<<'\n';
        }
        else{
            cout<<"wrong"<<'\n';
        }
    }
    else{
        if(pow(maxi,2)==w*w+s*s){
            cout<<"right"<<'\n';
        }
        else{
            cout<<"wrong"<<'\n';
        }
    }
    }
    return 0;
}