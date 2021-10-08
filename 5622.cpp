#include <iostream>
#include <string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int total=0;
    for(char ch:str){
        if(ch=='Z'){
            total+=10;
        }
        else{
            if((int)ch - 'A'>=18){
                
                total+=(ch-'B')/3+3;
            }
            else{
                total+=(ch-'A')/3+3;
            }
        }
    }
    cout<<total<<endl;
    return 0;
}