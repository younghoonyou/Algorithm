#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    int N;
    stack<int> s;
    stack<int> v;
    char control,add;
    cin>>str;
    for(char ch:str){
        s.push(ch);
    }
    cin>>N;
    str="";
    for(int i=0;i<N;++i){
        cin>>control;
        if(control=='P'){
            cin>>add;
            s.push(add);
        }
        else if(control=='L'){
            if(s.empty()){
                continue;
            }
            v.push(s.top());
            s.pop();
        }
        else if(control=='D'){
            if(v.empty()){
                continue;
            }
            s.push(v.top());
            v.pop();
        }
        else if(control=='B'){
            if(s.empty()){
                continue;
            }
            s.pop();
        }
    }
    while(!s.empty()){
        str+=s.top();
        s.pop();
    }
    reverse(str.begin(),str.end());
    while(!v.empty()){
        str+=v.top();
        v.pop();
    }
    cout<<str;
    return 0;
}