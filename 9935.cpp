#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int main(){
    string str,boom;
    char past = ' ';
    string temp;
    cin>>str;
    int count=0;
    cin>>boom;
    stack<char> s;
    for(char ch:str){
        int size = boom.size();
        if(s.top()==boom[count]){
            count++;
            if(ch==boom[count]){
                temp+=s.top();
            }
            else{
                temp.clear();
                count=0;
            }
        }
        s.push(ch);
        if(temp==boom){
            while(size--){
                s.pop();
            }
            temp.clear();
            count=0;
        }
    }
        while(!s.empty()){
            cout<<s.top();
            s.pop();
        }
    return 0;
}