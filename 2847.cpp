#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,count=0,temp;
    cin>>N;
    int level[N];
    for(int i=0;i<N;++i){
        cin>>level[i];
    }
    int i=N-1;
    while(i!=0){
        temp=level[i];
        i--;
        if(temp<=level[i]){
            while(temp<=level[i]){
                level[i]--;
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}