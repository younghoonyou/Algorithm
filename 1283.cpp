#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int N;
vector<char> v;
vector<string> buf;
int search(string s){
    bool flag = false;
    if(v.empty()) return 0;
    istringstream ss(s);
    string buff;
    vector<string> temp;
    while(getline(ss,buff,' ')){
        temp.push_back(buff);
    }
    for(int i=0;i<temp.size();++i){
        for(int j=0;j<v.size();++j){
            if(temp[i][0]==v[i]) flag = true;
        }
        if(!flag){v.push_back(temp[i][0]);return i;}
    }
    return 0;
}
int main(){
    cin>>N;
    string str;
    for(int i=0;i<=N;++i){
        getline(cin,str);
        buf.push_back(str);
    }
    buf.pop_back();
    for(int i=1;i<=N;++i){
        buf[i].insert(search(buf[i]),1,'[');
        buf[i].insert(search(buf[i])+2,1,']');
        cout<<buf[i]<<'\n';
    }
    return 0;
}