#include <iostream>
#include <set>
using namespace std;
int main(){
    int N,a;
    set<int> s;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a;
        s.insert(a);
    }
    for(auto i : s){
        cout<<i<<" ";
    }
    return 0;
}