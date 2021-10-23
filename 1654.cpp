#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n,m,start=0,count=0;
    cin>>n>>m;
    vector<long long> cable(n);
    for(long long i=0;i<n;++i){
        cin>>cable[i];
    }
    long long maxi = *max_element(cable.begin(),cable.end());
    while(start<=maxi){
        long long count=0;
        if((start+maxi) == 1){
            maxi=1;
            break;
        }
        long long mid = (start+maxi)/2;
        for(auto i:cable){
            count+=i/mid;
        }
        count<m ? maxi = mid-1:start=mid+1;
        // cout<<mid<<" ";
    }
    cout<<maxi;
    return 0;
}