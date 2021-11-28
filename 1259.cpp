#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    string temp;
    while(1){
        cin>>str;
        if(stoll(str)==0) return 0;
        temp = str;
        reverse(str.begin(),str.end());
        if(str==temp) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }
    return 0;
}