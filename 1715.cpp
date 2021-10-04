#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int N,temp,temp1,temp2;
    long long total=0;
    priority_queue<int, vector<int>, greater<int>> arr;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        arr.push(temp);
    }
    while(arr.size()!=1){
        temp1=arr.top();
        arr.pop();
        temp2=arr.top();
        arr.pop();
        total+=temp1+temp2;
        arr.push(temp1+temp2);
    }
cout<<total<<endl;
    return 0;
}