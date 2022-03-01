#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
stack<char> s;
int main(){
    string str;
    cin>>str;
    for(char ch:str){
        if(s.empty()) s.push(ch);
        else{
            if(ch==')'&&s.top()=='(') s.pop();
            else s.push(ch);
            }
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
    return 0;
}