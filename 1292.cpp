#include <iostream>
using namespace std;
int arr[1001];
int num(int n){
    int sum=0;
    int i=1;
    while(n!=i-1){
        sum+=i;
        i++;
    }
    return sum;
}
int main(){
    int a,b;
    int sum=0;
    cin>>a>>b;
    int i=1;
    while(num(i)<=b){
        for(int j=num(i-1)+1;j<=num(i);++j){
            arr[j] = i;
        }
        i++;
    }
    for(int k=a;k<=b;++k){
        cout<<arr[k]<<" ";
        sum+=arr[k];
    }
    cout<<sum;
    return 0;
}