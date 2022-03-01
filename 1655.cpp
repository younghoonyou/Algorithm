#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    priority_queue<int,vector<int>,greater<int> > q;
    stack<int> s;
    int N,temp;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        q.push(temp);
        int a = q.size();
        if(a&1){
        for(int j=0;j<(a-1)/2;++j){
            s.push(q.top());
            q.pop();
        }
    }
    else{
        for(int j=0;j<(a/2)-1;++j){
            s.push(q.top());
            q.pop();
        }
    }
    cout<<q.top()<<'\n';
    while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
    }
    return 0;
}