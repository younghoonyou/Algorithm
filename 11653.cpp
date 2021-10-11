#include <iostream>
#include <vector>
using namespace std;
int arr[10000002];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int  N,temp;
    int count=0;
    vector<int> div;
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=1000001;++i){
        if(arr[i]){
            continue;
        }
        for(int j=2*i;j<=1000001;j+=i){
            arr[j]++;
        }
    }
    cin>>N;
    temp = N;
    for(int i=0;i<=N;++i){
        if(!arr[i]){
            while(temp%i==0){
                
                temp/=i;
                div.push_back(i);
            }
        }
    }
    for(int j=0;j<div.size();++j){
            cout<<div[j]<<'\n';
    }
    return 0;
}