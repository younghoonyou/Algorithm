#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    long long  n,m;
    long long  count=0,start=0;
    cin>>n>>m;
    vector<int> temp(n);
    for(long long i=0;i<n;++i){
        cin>>temp[i];
    }
    long long maxi = *max_element(temp.begin(),temp.end());
    maxi--;
    while(start<=maxi){
        long long count=0;
        long long mid = (start+maxi)/2;
        for(auto i:temp){
            i-mid<0 ? count+=0:count+=i-mid;
        }
        count<m ? maxi = mid-1:start=mid+1;
    }
    cout<<maxi;
    return 0;
}