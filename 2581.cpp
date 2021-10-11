#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int arr[10001]={};
    int start,end;
    int total=0;
    vector<int> temp;
    cin >> start;
    cin >> end;
    arr[0]=1;
    arr[1]=1;
    for(int i=2;i<=end;++i){
        if(arr[i]){
            continue;
        }
        for(int j=2*i;j<=end;j+=i){
            arr[j]++;
        }
    }
    for(int i=start;i<=end;i++){
        if(!arr[i]){
            temp.push_back(i);
        }
    }
    if(temp.empty()){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<temp.size();++i){
        total+=temp[i];
    }
    cout<<total<<endl;
    cout<<*min_element(temp.begin(),temp.end());
    return 0;
}