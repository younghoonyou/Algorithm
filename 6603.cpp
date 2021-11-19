#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[50];
bool v[50];
int answer[14];
void lotto(int n){
    answer[0] = 0;
    if(n==7){
        for(int i=1;i<=6;++i){
            cout<<answer[i]<<" ";
        }
        cout<<'\n';
        return;
        // exit(0);
    }

        for(int j=1;j<=N;++j){
            if(!v[j]&&answer[n-1]<arr[j]){
                answer[n] = arr[j];
                v[j] = true;
                lotto(n+1);
                v[j] = false;
            }
        }
}
int main(){
    while(1){
    cin>>N;
    if(N==0) return 0;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
    }
    lotto(1);
    cout<<'\n';
    }
    return 0;
}