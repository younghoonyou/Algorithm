#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(){
    int N;
    string str;
    char s,temp;
    stack<char> what;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>str;
        for(char ch:str){
            what.push(ch);
            s = what.top();
            if(what.size()>=2){
                what.pop();
                temp = what.top();
                what.push(s);
            }
        if((what.top()==41)&&(temp==40)&&(what.size()>1)){
        what.pop();
        what.pop();
            }
        }    
        if(what.size()==0){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
        while(what.size()!=0){what.pop();}
    }
    return 0;
}