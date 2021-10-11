#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
    string croa[8] = {"c=","c-","dz=","d-","lj","nj","s=","z="};
    string temp;
    int count=0;
    string str;
    cin>>str;
    for(int i=0;i<8;++i){
        while(str.find(croa[i])!=string::npos)
        {
            str.replace(str.find(croa[i]),croa[i].length()," ");
            count++;
        }
    }
    for(char ch:str){
        if(ch!=' '){
            temp+=ch;
        }
    }
    cout<<count+temp.length();
    return 0;
}