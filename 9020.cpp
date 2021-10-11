#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int N,temp,front,back,cmp=99;
    int a,b;
    vector<int> add;
    cin>>N;
    int arr[10001]={};
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=10000;++i){
        if(arr[i]){
            continue;
        }
        for(int j=2*i;j<=10000;j+=i){
            arr[j]++;
        }
    }
    for(int i=0;i<N;++i){
        cin>>temp;
        for(int j=0;j<temp;++j){
            if(!arr[j]){
                add.push_back(j);
            }
        }
        for(int j=0;j<add.size();++j){
            for(int k=j;k<add.size();++k){
                if(add[j]+add[k] == temp){
                    cmp = min(cmp,abs(add[k]-add[j]));
                    front = add[j];
                    back = add[k];
                }
            }
        }
        cout<<front<<" "<<back<<endl;
        add.clear();
    }
    return 0;
}