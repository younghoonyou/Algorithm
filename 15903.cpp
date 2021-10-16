#include <iostream>
#include <queue>
using namespace std;
int main(){
    long long arr[1000001]={0,};
    long long N,M,total=0;
    priority_queue<long long,vector<long long>,greater<long long> > q;
    cin>>N>>M;
    for(long long i=0;i<N;++i){
        cin>>arr[i];
        q.push(arr[i]);
    }
    for(long long i=0;i<M;++i){
        long long x = q.top();
        q.pop();
        long long y = q.top();
        q.pop();
        q.push(x+y);
        q.push(x+y);
    }
    while(!q.empty()){
        total+=q.top();
        q.pop();
    }
    cout<<total;
    return 0;
}