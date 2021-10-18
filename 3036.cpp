#include <iostream>
#include <algorithm>
using namespace std;
int gcd(int a,int b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b,a%b);
    }
}
int main(){
    int N;
    int arr[10001]={0,};
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    for(int i=1;i<N;++i){
        cout<<arr[0]/gcd(arr[0],arr[i])<<"/"<<arr[i]/gcd(arr[0],arr[i])<<'\n';
    }
    
    return 0;
}