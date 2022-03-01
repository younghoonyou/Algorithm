#include <iostream>
#include <string>
using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int len;
    int count=0;
    a.length()<b.length() ? len=a.length():len=b.length();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<len;++i){
            if(a[i]!=b[i]){
                count++;
            }
        }
    cout<<count;
    return 0;
}