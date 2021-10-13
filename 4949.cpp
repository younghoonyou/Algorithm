#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    string str;
    int count=0;
    stack<int> temp;
    while(getline(cin,str,'.')){
        if(str.length()==1){break;}
        char first,second;
        for(char ch:str){
            if(ch==41||ch==40||ch==91||ch==93){
                temp.push(ch);
            }
            if(temp.size()>1){
                first = temp.top();
                temp.pop();
                second = temp.top();
                temp.push(first);
            }
            if((first==41&&second==40&&temp.size()>1)||(first==93&&second==91&&temp.size()>1)){
                temp.pop();
                temp.pop();
            }
        }
        if(temp.size()==0){
            cout<<"yes"<<'\n';
        }
        else{
            cout<<"no"<<'\n';
        }
        while(temp.size()!=0){temp.pop();}
    }
    return 0;
}