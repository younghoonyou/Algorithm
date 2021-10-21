#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(string a,string b){
    int i=0;
    while(a[i]==b[i]){
        i++;
    }
    return a[i]<b[i];
}
int main(){
    string str;
    vector<string> temp;
    cin>>str;
    int N = str.length();
    for(int i=0;i<N;++i){
            temp.push_back(str);
            str.erase(0,1);
        }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<temp.size();++i){
        cout<<temp[i]<<'\n';
    }
    return 0;
}