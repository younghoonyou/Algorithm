#include <iostream>
#include <queue>
using namespace std;
int main(){
    int N,top;
    cin>>N;
    queue<int> temp;
    for(int i=1;i<=N;++i){
        temp.push(i);
    }
    while(temp.size()!=1){
        temp.pop();
        top = temp.front();
        temp.pop();
        temp.push(top);
    }
    cout<<temp.front();
    return 0;
}