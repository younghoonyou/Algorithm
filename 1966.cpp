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
        cin>>what>>where;//배열 개수, 탐색
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
                // cout<<"TOP:"<<answer.top()<<" "<<"Box_first:"<<box_first<<endl;
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


        // for(int j=0;j<what;++j){
        // while(box.front().first!=import[j]){
        //     int box_first = box.front().first;
        //     int box_second = box.front().second;
        //     box.pop();
        //     box.push(make_pair(box_first,box_second));
        // }
        // if(box.front().second==where){
        //     break;
        // }
        // count++;
        // box.pop();
        // }
        // cout<<count<<'\n';
        while(!box.empty()) box.pop();
        while(!answer.empty()) answer.pop();
        import.clear();
        // while(box.front().second<=){//정렬
        // int top_first = box.front().first;
        // int top_second = box.front().second;
        // box.pop();
        // box.push(make_pair(top_first,top_second));
        // }
        
    }
    return 0;
}