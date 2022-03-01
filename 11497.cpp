#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int N,n,num,maxim;
    vector<int> temp;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>n;
        for(int j=0;j<n;++j){
            cin>>num;
            temp.push_back(num);
        }
        sort(temp.begin(),temp.end());
        sort(temp.begin(),temp.begin()+(temp.size()+1)/2,cmp);
        maxim = max(abs(*max_element(temp.begin(),temp.end())-),abs());
    }
    return 0;
}