#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int N;
vector<int> v;
vector<char> oper;
string str;
int main(){
    cin>>N;
    cin>>str;
    for(char ch:str){
        if(isalnum(ch)) v.push_back(ch - '0');
        else oper.push_back(ch);
    }
    
    return 0;
}