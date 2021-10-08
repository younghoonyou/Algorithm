#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main(){
    string str;
    string temp;
    vector<string> x;
    char s='.';
    bool flag = true;
    int i=0;
    getline(cin,str);
    while(str[0]==' '){
        str = str.erase(0,1);
    }
    while(str.back()==' '){
        str.pop_back();
    }
    if(str.find(' ')==string::npos&&str.length()>0){
        cout<<1<<endl;
        return 0;
    }
    for(char ch:str){
        if(ch==' '){
            if(s!=ch){
            x.push_back(temp);
            temp="";
            s = ch;
            }
            continue;
        }
        temp+=ch;
        s = ch;

    }
    if(x.empty()){
        cout<<0<<endl;
        return 0;
    }
    cout<<x.size()+1<<endl;
    return 0;
}