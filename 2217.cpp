#include <iostream>
#include <vector>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int N,answer;
    cin>>N;
    vector<int> temp(N);
    for(int i=0;i<N;++i){
        cin>>temp[i];
    }
    sort(temp.begin(),temp.end(),cmp);
    for(int i=0;i<N;++i){
        temp[i]=temp[i]*(i+1);
    }
    answer=*max_element(temp.begin(),temp.end());
    cout<<answer;
    return 0;
}