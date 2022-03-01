#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n,c;
    cin>>n>>c;
    vector<int> temp(n);
    for(int i=0;i<n;++i){
        cin>>temp[i];
    }
    int start=0;
    int end = n-1;
    int i=0;
    sort(temp,temp+n);
    while(start<=end){
        int mid = (start+end)/2;
        if(temp[mid]>temp[i]){
            start = mid + 1;
        }
        else if(temp[mid]<temp[i]){
            end = mid - 1;
        }
        else{

        }
        i++;
    }
    return 0;
}