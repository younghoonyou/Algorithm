#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str,make;
    cin>>make;
    cin>>str;
    while(str!=make){
        if(str[str.length()-1]=='B'){
            str.pop_back();
            reverse(str.begin(),str.end());
        }
        else if(str[str.length()-1]=='A'){
            str.pop_back();
        }
        if(str.length()==0){
            cout<<0;
            return 0;
        }
    }
    cout<<1;
    return 0;
}