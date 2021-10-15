#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[500001]={};
    int find[500001]={};
    int answer[500001]={};
    int N,n;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>find[i];
    }
    sort(arr,arr+N);

    for(int i=0;i<n;++i){
        answer[i]=upper_bound(arr,arr+N,find[i])-lower_bound(arr,arr+N,find[i]);
    }
    for(int i=0;i<n;++i){
        cout<<answer[i]<<" ";
    }
    return 0;
}