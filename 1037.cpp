#include <iostream>
#include <algorithm>
using namespace std;
int arr[51];
int main(){
    int n,a,b;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    a = *min_element(arr,arr+n);
    b = *max_element(arr,arr+n);
    cout<<a*b;
    return 0;
}