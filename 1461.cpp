#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N,M;
int arr[50];
bool v[50];
int sum = 0;
int main(){
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    if(N==1){cout<<arr[0]<<'\n';return 0;}
    sort(arr,arr+N);
    int start = 0,end = N-1;
    if(abs(arr[start])>abs(arr[end])){
        sum+=abs(arr[start]);
        for(int i=0;i<start+M;++i) v[i] = true;
    }
    else if(abs(arr[start])<abs(arr[end])){
        sum+=abs(arr[end]);
        for(int i=end;i>end-M;--i) v[i] = true;
    }
    else{
        int start_temp = 0,end_temp=N-1;
        while(abs(arr[start_temp])==abs(arr[end_temp])&&start_temp<=end_temp){
            start_temp++;
            end_temp--;
        }
        if(abs(arr[start_temp])<abs(arr[end_temp])){
            sum+=abs(arr[start]);
            for(int i=0;i<start+M;++i) v[i] = true;
        }
        else{
            sum+=abs(arr[end]);
            for(int i=end;i>end-M;--i) v[i] = true;
        }
    }

    int p_start = 0,p_end = N-1;
    while(p_start<=p_end){
        int cen = (p_start+p_end)/2;
        if(arr[cen]>0){
            p_end = cen - 1;
        }
        else{
            p_start = cen + 1;
        }
    }

    for(int i=start;i<p_start;++i){
        if(v[i]) continue;
        if(i+M>p_start){
            sum+=2*abs(arr[i]);
            for(int j=i;j<p_start;++j) v[j] = true;
            break;
        }
        sum+=2*abs(arr[i]);
        for(int j=i;j<i+M;++j) v[j] = true;
    }
    for(int i=end;i>=p_start;--i){
        if(v[i]) continue;
        if(i-M<p_start-1){
            sum+=2*abs(arr[i]);
            for(int j=i;j>=p_start;--j) v[j] = true;
            break;
        }
        sum+=2*abs(arr[i]);
        for(int j=i;j>i-M;--j) v[j] = true;
    }
    cout<<sum<<'\n';
    return 0;
}