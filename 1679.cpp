#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dp[100001][100001][100001];
bool v[100001];
int start,finish;
int bfs(int start){
    int count=0;
    queue<int> q;
    q.push(start);
    v[start] = true;
    while(!q.empty()){
        int x = q.front();
        int one = x-1;
        int two = x+1;
        int three = 2*x;
        if(one==finish||two==finish||three==finish){
            return count;
        }
        q.pop();
        if(one<0||three>finish||two>finish||one==start||two==start||three==start){
            continue;
        }
        q.push(one);
        q.push(two);
        q.push(three);
        count[] = count + 1;
    }
    return count;
}
int main(){
    int end;
    cin>>start>>finish;
    cout<<bfs(start);
    return 0;
}