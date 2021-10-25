#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N,M;
    cin>>N;
    vector<int> arr(N);
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    cin>>M;
    vector<int> search(M);
    for(int i=0;i<M;++i){
        cin>>search[i];
    }
    sort(arr.begin(),arr.end());
    int maxi = arr[0];
    for(int i=0;i<M;++i){
        bool flag = false;
        int x = search[i];
        int start=0;
        int end = N-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]<x){
                start = mid + 1;
            }
            else if(arr[mid]>x){
                end = mid - 1;
            }
            else{
                cout<<1<<" ";
                flag = true;
                break;
            }
        }
        if(!flag){
            cout<<0<<" ";
        }
    }
    return 0;
}