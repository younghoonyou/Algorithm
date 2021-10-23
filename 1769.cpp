#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    string str;
    int cnt=0,total;
    cin>>str;
    while(str.length()!=1){
        total=0;
        for(char ch:str){
            total+=ch-'0';
        }
        str = to_string(total);
        cnt++;
    }
    cout<<cnt<<'\n';
        if(stoi(str)%3!=0){
        cout<<"NO";
    }
    else{
        cout<<"YES";
    }
    return 0;
}