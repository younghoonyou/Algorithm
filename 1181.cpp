#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
using namespace std;
bool cmp(string a,string b){
    if(a.length()==b.length()){
        return a<b;
    }
    return a.length()<b.length();
}
int main(){
    int N;
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<string> str;
    string temp;
    cin>>N;
    for(int i=0;i<N;++i){
    cin>>temp;
    str.push_back(temp);
    }
    sort(str.begin(),str.end(),cmp);
    str.erase(unique(str.begin(),str.end()),str.end());
    for(int i=0;i<str.size();++i){
        cout<<str[i]<<'\n';
    }
    return 0;
}