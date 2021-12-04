#include <iostream>
#include <algorithm>
using namespace std;
int arr[21][21];
bool v[21];
int N,answer=1234567890;
void start_link(int n,int start){
    if(n==N/2){
        int a=0,b=0;
        for(int i=0;i<N;++i){
            for(int j=i+1;j<N;++j){
                if(v[i]&&v[j]){
                    a+=arr[i][j];
                    a+=arr[j][i];
                }
                else if(!v[i] && !v[j]){
                    b+=arr[i][j];
                    b+=arr[j][i];
                }
            }
        }
        answer = min(answer,abs(a-b));
    }
    for(int i=0;i<N;++i){
        if(!v[i] && i>start){
            v[i] = true;
            start_link(n+1,i);
            v[i] = false;
        }
    }
}
int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            cin>>arr[i][j];
        }
    }
    start_link(0,-1);
    cout<<answer<<'\n';
    return 0;
}