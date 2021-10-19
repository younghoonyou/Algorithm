#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int N,count=0,maxi=-1;
    cin>>N;
    vector<int> temp(N);
    vector<int> cnt;
    for(int i=0;i<N;++i){
        cin>>temp[i];
    }
    for(int i=0;i<N-1;++i){
        for(int j=i+1;j<N;++j){
            if(temp[i]>temp[j]){
                count++;
                if(maxi<count){
                maxi = count;
            }
            }
            else{
                break;
            }
        }
        count=0;
    }
    cout<<maxi;
    return 0;
}