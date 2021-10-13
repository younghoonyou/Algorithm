#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int> temp(N);
    vector<int> answer(N,-1);
    stack<int> box;
    for(int i;i<temp.size();i++){
        cin>>temp[i];
    }
    for(int i=0;i<N;++i){
       while(!box.empty()&&temp[box.top()]<temp[i]){
           answer[box.top()] = temp[i];
           box.pop();
       }
       box.push(i);
    }
    for(auto i : answer) cout<<i<<" ";
    return 0;
}