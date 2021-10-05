#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    int zero=0,one=0;
    int flag;
    int answer;
    cin>>str;
    flag=2;
    for(char ch:str){
        if(flag!=0&&ch=='0'){
            zero++;
            flag=0;
        }
        else if(flag!=1&&ch=='1'){
            one++;
            flag=1;
        }
    }
    answer=min(zero,one);
    cout<<answer;
}