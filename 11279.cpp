#include <iostream>
#include <queue>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,n;
    priority_queue<int> answer;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>n;
        if(n==0){
            if(answer.empty()){
                cout<<0<<'\n';
            }
            else{
                cout<<answer.top()<<'\n';
                answer.pop();
            }
        }
        else{
            answer.push(n);
        }
    }
    return 0;
}