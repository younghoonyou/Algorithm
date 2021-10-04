#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string str;
    string stop="Was it a cat I saw?";
    string temp="";
    int cnt=2;
    while(1){
        getline(cin, str);
        if(str==stop){
            break;
        }
        for(int j=0;j<str.length();j+=cnt){
            temp+=str[j];
        }
        cout<<temp<<endl;
        temp="";
        cnt++;
    }
    return 0;
}