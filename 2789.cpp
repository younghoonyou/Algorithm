#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N,num;
    int total=0;
    cin>>N>>num;
    vector<int> temp(N);
    for(int i=0;i<N;++i){
        cin>>temp[i];
    }
    cout<<endl;
    sort(temp.begin(),temp.end());
    for(int i=0;i<temp.size();++i){
        cout<<temp[i]<<" ";
    }
    return 0;
}