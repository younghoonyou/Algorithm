#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int s[10001];
int e[10001];
vector<int> answer;
string a,b,end;
int main(){
    cin>>a>>b;
    if(a.length()<b.length()){
        string temp;
        temp = a;
        a = b;
        b = temp;        
    }
    for(int i=0;i<a.length();i++){
        s[i+1]=a[i] - '0';
    }
    for(int i=0;i<b.length();i++){
        e[i+1+(a.size()-b.size())]=b[i] - '0';
    }
    for(int i=a.size();i>0;i--){
        int sum = s[i] + e[i];
        if(sum>=10){
            s[i-1]++;
            sum-=10;
        }
        answer.push_back(sum);
    }
    if(s[0]!=0){cout<<1;}
    for(int i=answer.size()-1;i>=0;--i){
        cout<<answer[i];
    }
    return 0;
}