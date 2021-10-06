#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main(){
    string str;
    int temp,count=0;
    int start = 1;
    cin>>str;
    for(char ch:str){
        temp = ch-'A'+1;
        if(abs(temp-start)>13){
            count+=26-abs(temp-start);
        }
        else{
            count+=abs(temp-start);
        }
        start=temp;
    }
    cout<<count<<endl;
    return 0;
}