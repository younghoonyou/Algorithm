#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<int> > arr;
vector<int> temp;
bool v[1001];
void bfs(int start){
    queue<int> q;
    v[start] = true;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<' '<<endl;
            for(int i=0;i<arr[x].size();++i){
                int y = arr[x][i];
                if(!v[y]){
                    q.push(y);
                    v[y] = true;
                }
            }
    }
}
int main(){
    int N,link;
    int start,end;
    cin>>N;
    for(int i=1;i<=N;++i){
        temp.push_back(i);
    }
    for(int i=1;i<=N;++i){
        arr.push_back(temp);
    }
    // cin>>link;
    cout<<arr[0][0];
    // arr.push_back(temp);
    // cout<<arr[1].size();
    // for(int i=0;i<link;++i){
    //     arr.push_back(start);
    //     cin>>start>>end;
        
    //     arr[start].push_back(end);
    // }
    // bfs(1);
    return 0;
}