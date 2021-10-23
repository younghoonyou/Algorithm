#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    string search,temp;
    int count=0,i=0;
    getline(cin,str);
    getline(cin,search);
    while(str.find(search)!=string::npos){
        int pos = str.find(search);
        str = str.substr(pos+search.length(),str.length());
        count++;
    }
    cout<<count;
    return 0;
}