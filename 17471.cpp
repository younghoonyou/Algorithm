#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
int person[11];
vector<int> zone[11];
bool visit[11];
int one_sum=0,two_sum=0;

bool check(){
    for(int i=1;i<=N;++i){
        for(int j=1;zone[i].size();++j){
            
        }
    }
    return false;
}

void dfs(int n){
    queue<int> q;
    q.push(n);
    visit[n] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<zone[x].size();++i){
            int y = zone[x][i];
            if(!visit[y]){
                visit[y] = true;
                q.push(y);
            }
        }
    }
}


void divide(int n){
    queue<int> q;
    q.push(n);
    visit[n] = true;
    while(!q.empty()){

    }
}

int main(){
    int tmp;
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>person[i];
    }

    for(int i=1;i<=N;++i){
        cin>>M;
        for(int j=1;j<=M;++j){
            cin>>tmp;
            zone[i].push_back(tmp);
            // zone[tmp].push_back(i);
        }
    }

    // for(int i=1;i<=N;++i){
    //     cout<<zone[i].size()<<'\n';
    // }

    dfs(1);
    // cout<<'\n'<<"=============================="<<'\n';
    return 0;
}