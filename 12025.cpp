#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string temp;
    int k,count=0;
    cin>>temp;
    cin>>k;
    reverse(str.begin(),str.end());
    while(){
        string str = temp;
    for(char ch:str){
        if(ch-'0'==7){
            str[str.find('7')]='2';
            reverse(str.begin(),str.end());
            cout<<str;
            break;
        }
        else if(ch-'0'==2){
            str[str.find('7')]='2';
            reverse(str.begin(),str.end());
            cout<<str;
            break;
        }
        else if(ch-'0'==6){
            str[str.find('7')]='2';
            reverse(str.begin(),str.end());
            cout<<str;
            break;
        }
        else if(ch-'0'==1){
            str[str.find('7')]='2';
            reverse(str.begin(),str.end());
            cout<<str;
            break;
        }
    }
    if(stoi(s)<stoi(str)){
        count++;
    }
    }
    return 0;
}