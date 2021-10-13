#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,count=1;
    stack<int> answer;
    cin>>N;
    vector<char> good;
    for(int i=0;i<N;++i){
        int x;
        cin>>x;
        while(count<=x){
            answer.push(count);
            count++;
            good.push_back('+');
        }
        if(answer.top()==x){
            answer.pop();
            good.push_back('-');

        }
        else{
            cout<<"NO";
            return 0;
        }

    }
    for(int i=0;i<good.size();++i){
        cout<<good[i]<<'\n';
    }
    return 0;
}