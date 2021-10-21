#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int main(){
    string answer;
    int N,th,count=1;
    cin>>N>>th;
    queue<int> q;
    for(int i=1;i<=N;++i){
        q.push(i);
    }
    // cout<<"<";
    answer+="<";
    while(!q.empty()){
        int x = q.front();
        if(count%th==0){
            answer+=to_string(x)+", ";
            q.pop();
            count=1;
        }
        else{
        q.pop();
        q.push(x);
        count++;
        }
    }
    answer.pop_back();
    answer.pop_back();
    answer+=">";
    cout<<answer;
    return 0;
}