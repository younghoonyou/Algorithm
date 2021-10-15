#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    queue<pair<int,int> > box;
    priority_queue<int> answer;
    int N,what,where;
    cin>>N;
    for(int i=0;i<N;++i){
        int count=0;
        cin>>what>>where;
        vector<int> import(what);
        for(int j=0;j<what;++j){
            cin>>import[j];
            box.push(make_pair(j,import[j]));
            answer.push(import[j]);
        }
        while(!box.empty()){
            int box_first = box.front().first;
            int box_second = box.front().second;
            if(box_second==answer.top()){
                answer.pop();
                count++;
                if(box_first == where){
                    cout<<count<<'\n';
                    break;
                }
                else{
                box.pop();
                box.push(make_pair(box_first,box_second));    
                }
            }
            else{
                box.pop();
                box.push(make_pair(box_first,box_second));
            }
        }
        while(!box.empty()) box.pop();
        while(!answer.empty()) answer.pop();
        import.clear();
    }
    return 0;
}