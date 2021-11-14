#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int N,a,b;
    for(int i=0;i<N;++i){
        cin>>a>>b;
        int an = (pow(a,b))%10;
        cout<<an;
    }
    return 0;
}