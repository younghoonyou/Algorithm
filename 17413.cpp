#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int count=0;
    bool flag=false;
    string str;
    string buffer;
    getline(cin,str);
    // istringstream ss(str);
    // string buffer;
    stack<char> good;
    string temp;
    // vector<string> temp;
    // while(getline(ss,buffer,' ')){
    //     temp.push_back(buffer);
    //     count++;
    // }
    // for(int i=0;i<temp.size();++i){
    //     reverse(temp[i].begin(),temp[i].end());
    //     if(i==temp.size()-1){
    //         cout<<temp[i];
    //     }
    //     else{
    //         cout<<temp[i]<<" ";
    //     }
    // }
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