#include <iostream>
#include <string>
using namespace std;
int main(){
    string str,boom,temp;
    cin>>str>>boom;
    for(int i=0;i<str.length();++i){
        int cnt=0;
        int trial = boom.length();
        temp+=str[i];
        if(str[i]==boom[boom.length()-1]){
            int j = 1;
            while(trial--){
                if(temp[temp.length()-j]==boom[trial]) cnt++;
                j++;
            }
            if(cnt==boom.length()){
                for(int k=0;k<boom.length();++k){
                    temp.pop_back();
                }
            }
        }
    }
    if(temp.length()==0) cout<<"FRULA"<<'\n';
    else cout<<temp<<'\n';
    return 0;
}