//https://www.acmicpc.net/problem/5014
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int answer[1000001];
bool v[1000001];
int main(){
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    queue<int> q;
    q.push(s);
    v[s] = true;
    answer[s] = 0;
    while(!q.empty()){
        int cur = q.front();
        if(cur == g){cout<<answer[g];return 0;}
        q.pop();
        for(int i=0;i<2;++i){
            int nx;
            if(i==0) nx = cur+u;
            else nx = cur-d;
            if(nx<1||nx>f||v[nx]) continue;
            answer[nx] = answer[cur] + 1;
            v[nx] = true;
            q.push(nx);
        }
    }
    cout<<"use the stairs";
    return 0;
}