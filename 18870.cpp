#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int main(){
    int count=0;
    int size;
    // cin>>N;
    scanf("%d",&N);
    vector<int> temp(N);
    vector<int> temp2(N);
    for(int i=0;i<N;++i){
        // cin>>temp[i];
        scanf("%d",&temp[i]);
    }
    temp2 = temp;
    sort(temp.begin(),temp.end());
    temp.erase(unique(temp.begin(),temp.end()),temp.end());
    size = temp.size();
    for(int i=0;i<N;++i){
        int start =0;
        int end = size;
        int mid = (start+end)/2;
        while(true){
            mid = (start+end)/2;
            if(temp[mid]>temp2[i]){
                end = mid - 1;
            }
            else if(temp[mid]<temp2[i]){
                start = mid + 1;
            }
            else{
                break;
            }
        }
        printf("%d ",mid);
        // cout<<count<<" ";
        count=0;
    }
    // for(int i=0;i<N;++i){
    // }
    return 0;
}