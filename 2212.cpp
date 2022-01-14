//https://www.acmicpc.net/problem/2212
#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000];
int dis[10000];
int main(){
    int N,K;
    int answer = 0;
    cin>>N>>K;
    for(int i=0;i<N;++i) cin>>arr[i];
    sort(arr,arr+N);
    for(int i=0;i<N-1;++i) dis[i] = arr[i+1] - arr[i];
    sort(dis,dis + N-1);
    for(int i=0;i<N-K;++i) answer+=dis[i];
    cout<<answer<<'\n';
    return 0;
}