#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    char temp;
    string answer;
    string str[51];
    bool flag = false;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>str[i];
    }
    for(int i=0;i<str[0].size();++i){
        for(int j=0;j<n-1;++j){
            for(int k=j+1;k<n;++k){
                if(flag) break;
                if(str[j][i]!=str[k][i]){answer+='?';flag = true;break;}
            }
        }
        if(!flag) answer+=str[0][i];
        flag = false;
    }
    cout<<answer;
}