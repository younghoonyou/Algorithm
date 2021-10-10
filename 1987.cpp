#include <iostream>
#include <vector>
using namespace std;
int arr[1001]={0,};
int main(){
    int N,i=0;
    int count=0;
    cin>>N;
    vector<int> temp(N);
    arr[0]=1;
    arr[1]=1;
    for(int i=0;i<N;++i){
        cin>>temp[i];
    }
    for(int i=1;i<=*max_element(temp.begin(),temp.end());++i){
        if(arr[i]){
            continue;
        }
        for(int j=2*i;j<=*max_element(temp.begin(),temp.end());j=j+i){
            arr[j]++;
        }

    }
    for(int i=0;i<N;++i){
        if(!arr[temp[i]]){
            count++;
        }
    }
    cout<<count;
    return 0;
}