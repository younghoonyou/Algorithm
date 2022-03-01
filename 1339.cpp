#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
bool cmp(string a,string b){
    return a.length()<b.length();
}
int main(){
    int N,total=0;
    cin>>N;
    vector<string>str(N);
    vector<int>num(N);
    for(int i=0;i<N;++i){
        cin>>str[i];
    }
    sort(str.begin(),str.end(),cmp);
    for(int i=0;i<N-1;++i){

        for(int j=0;j<str[i+1].length();j++){
            
        }
    }
    return 0;
}