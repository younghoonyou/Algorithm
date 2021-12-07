#include <iostream>
#include <algorithm>
#include <string>
using namespace std;//N극 0,S극 1
int tire[4][8];
int answer=0;
int main(){
    int K,num,circle;
    string str;
    for(int i=0;i<4;++i){
        cin>>str;
        for(int j=0;j<str.length();++j){
            tire[i][j] = str[j];
        }
    }
    cin>>K;
    for(int i=0;i<K;++i){
        cin>>num>>circle;

    }
    
    cout<<answer;
    return 0;
}