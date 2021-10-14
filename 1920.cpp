#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int arr[100001];
    int find[100001];
    int answer[100001]={0,};
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
        int start=0;
        int end = N-1;
        int mid = (start+end)/2;
        while(start<=end){
            mid = (start+end)/2;
            if(find[i]<arr[mid]){
                end = mid - 1;
            }
            else if(find[i]>arr[mid]){
                start = mid + 1;
            }
            if(find[i]==arr[mid]){
                answer[i]=1;
                break;
            }
        }
    }
    for(int i=0;i<n;++i){
        cout<<answer[i]<<'\n';
    }
    return 0;
}