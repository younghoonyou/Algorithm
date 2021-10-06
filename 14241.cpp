#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
    int N,temp;
    int total=0;
    int slime1,slime2;
    cin>>N;
    priority_queue<int,vector<int>,greater<int>> num;
    for(int i=0;i<N;++i){
        cin>> temp;
        num.push(temp);
    }
    while(num.size()!=1){
        slime1 = num.top();
        num.pop();
        slime2 = num.top();
        num.pop();
        num.push(slime1+slime2);
        total+=slime1*slime2;
    }
    cout<<total<<endl;
    return 0;
}