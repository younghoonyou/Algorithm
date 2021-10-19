#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int N,mini,rang,cent,maxi=-1;
double total=0,avg;
int main(){
    int index;
    scanf("%d",&N);
    vector<int> temp2(N);
    vector<int> temp(N);
    vector<int> arr_index;
    for(int i=0;i<N;++i){
        scanf("%d",&temp2[i]);
        total+=temp2[i];
    }
    vector<int> arr(N);
    sort(temp2.begin(),temp2.end());
    temp = temp2;
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    mini = temp[0];
    if(temp.size()!=1){
    for(int i=0;i<temp.size();++i){
        int count = upper_bound(temp2.begin(),temp2.end(),temp[i]) - lower_bound(temp2.begin(),temp2.end(),temp[i]);
        arr[i] = count;
        if(arr[i]>maxi){
            maxi = arr[i];
            index = i;
        }
    }
    for(int i=0;i<N;++i){
        if(i == index){
            continue;
        }
        if(arr[index] == arr[i]){
            arr_index.push_back(i);
        }
    }
    if(arr_index.empty()){
        mini = temp[index];
    }
    else{
        mini = temp[arr_index[0]];
    }
    }
    avg = round(total/N);
    cent = temp2[(N-1)/2];
    rang = temp2[temp2.size()-1] - temp2[0];
    printf("%d\n%d\n%d\n%d",(int)avg,cent,mini,rang);
    return 0;
}