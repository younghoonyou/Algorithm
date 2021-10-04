#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int N,total=0,temp,temp1,temp2;
    priority_queue<int, vector<int>, greater<int>> arr;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        arr.push(temp);
    }
    for(int i=0;i<N-1;++i){
        temp1=arr.top();
        arr.pop();
        temp2=arr.top();
        arr.pop();
        total+=temp1+temp2;
        arr.push(total);
    }
cout<<total;
    return 0;
}