#include <iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    (N+1)&1 ? cout<<"CY":cout<<"SK";
    return 0;
}