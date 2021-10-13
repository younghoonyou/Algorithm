#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> temp;
    long long N,a,total=0;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>a;
        if(a==0){
                temp.pop();
        }
        else{
            temp.push(a);
        }
    }
    while(temp.size()!=0){
        total+=temp.top();
        temp.pop();
    }
    cout<<total;
    return 0;
}