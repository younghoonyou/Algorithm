#include <iostream>
#include <stack>
using namespace std;

int hanoi(stack<int> &a,stack<int> &b,stack<int> &c){
//1
int count=0;
if(((a.top()>b.top())&&(a.top()<c.top()))||(c.empty()&&(a.top()>b.top()))){
    c.push(a.top());
    a.pop();
    count++;
    hanoi(a,b,c);
}
//2
else if(((a.top()>c.top())&&(a.top()<b.top()))||(b.empty()&&(a.top()>c.top()))){
    b.push(a.top());
    a.pop();
    count++;
    hanoi(a,b,c);
}
else if(((a.top()>c.top())&&(a.top()<b.top()))||(b.empty()&&(a.top()>c.top()))){
    b.push(a.top());
    a.pop();
    count++;
    hanoi(a,b,c);
}
//3

return count;
}
int main(){
    int N;
    cin>>N;
    stack<int> temp1;
    stack<int> temp2;
    stack<int> temp3;
    for(int i=N;i>0;i--){
        temp1.push(i);
    }
    cout<<hanoi(temp1,temp2,temp3);
    // while(hanoi(temp1,temp2,temp3)){

    // }
    // cout<<count;
    return 0;
}