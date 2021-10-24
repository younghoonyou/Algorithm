#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){
    int count=0;
    bool flag=false;
    string str;
    string buffer;
    getline(cin,str);
    stack<char> good;
    string temp;
    for(char ch:str){
        if(ch=='<'){
            while(!good.empty()){
                temp+=good.top();
                good.pop();
            }
            temp+=ch;
            flag=true;
            continue;
        }
        else if(ch=='>'){
            temp+=ch;
            flag=false;
            continue;
        }
        if(flag){
            temp+=ch;
            continue;
        }
        else{
            if(ch==' '){
                while(!good.empty()){
                    temp+=good.top();
                    good.pop();
                }
                temp+=ch;
            }
            else{
                good.push(ch);
            }
        }
    }
    while(!good.empty()){
                    temp+=good.top();
                    good.pop();
                }
    cout<<temp;
    return 0;
}