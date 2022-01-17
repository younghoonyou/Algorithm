//https://www.acmicpc.net/problem/1461
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N,M;
int arr[50];
int p_index = 0;
int sum = 0;
int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>arr[i];
        if(arr[i]<0) p_index++;//인덱스를 구하는 센스
    }
    sort(arr,arr+N);
    for(int i=0;i<p_index;i+=M) sum+=2*abs(arr[i]);
    for(int i=N-1;i>=p_index;i-=M) sum+=2*abs(arr[i]);
    sum = min(sum-abs(arr[0]),sum-abs(arr[N-1]));
    cout<<sum;
    return 0;
}//연산하고 나중에 빼주는 방식