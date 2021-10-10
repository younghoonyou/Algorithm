#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,count=0;
    int j=0;
    int flag=0;
    cin>>N;
    vector<string> str(N);
    for(int i=0;i<N;++i){
        cin>>str[i];
    }
    for(int i=0;i<N;++i){
        str[i].erase(unique(str[i].begin(),str[i].end()),str[i].end());
    }
    for(int i=0;i<N;++i){
        int a = str[i].length();
        for(int j=0;j<a;j++){
            char temp = str[i][0];
            str[i].erase(0,1);
            if(str[i].find(temp)!=string::npos){
                break;
            }
        }
        if(str[i].length()==0){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}