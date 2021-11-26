#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000001];
int gcd(int a,int b){
    int tmp;
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    int N;
    int gcd_num;
    int count=0;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    gcd_num = arr[1] - arr[0];
    for(int i=1;i<N;++i){
        gcd_num = gcd(gcd_num,arr[i]-arr[i-1]);
    }
    int answer = arr[0];
    int i=1;
    while(answer != arr[N-1]){
        answer+=gcd_num;
        if(answer!=arr[i]) count++;
        else i++;
    }
    cout<<count;
    return 0;
}