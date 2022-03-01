#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N,i=1;
    int ex;
    cin>>N;
    vector<int> temp(N);
    for(int i=0;i<N;++i){
        cin>>temp[i];
    }
    sort(temp.begin(),temp.end());
    ex = temp[0];
    return 0;
}