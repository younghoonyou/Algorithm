#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main(){
    string N,n;
    int a,b;
    cin >> N >> n;
    reverse(N.begin(),N.end());
    reverse(n.begin(),n.end());
    a = stoi(N);
    b = stoi(n);
    if(a>b){
        cout<<a<<endl;
    }
    else{
        cout<<b<<endl;
    }
    return 0;
}