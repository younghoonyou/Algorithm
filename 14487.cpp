#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,total=0;
    cin>>N;
    vector<int> temp(N);
    for(int i=0;i<N;++i){
        cin>>temp[i];
        total+=temp[i];
    }
    total-=*max_element(temp.begin(),temp.end());
    cout<<total<<endl;
    return 0;
}