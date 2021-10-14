#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,seq,count=1;
    queue<int> answer;
    cin>>N>>seq;
    for(int i=1;i<=N;++i){
        answer.push(i);
    }
    cout<<"<";
    while(!answer.empty()){
        int temp = answer.front();
        if(count%seq==0){
            answer.pop();
            if(answer.empty()){
                cout<<temp<<">";
            }
            else{
                cout<<temp<<","<<" ";
            }
        }
        else{
            answer.pop();
            answer.push(temp);
        }
        count++;
    }
    return 0;
}