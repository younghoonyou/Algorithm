#include <iostream>
#include <algorithm>
using namespace std;
bool arr[1000001]={true,true,};
int N;
void sosu(){
    for(int i=2;i<=1000000;++i){
        for(int j=2*i;j<=1000000;j+=i){
            if(arr[j]) continue;
            arr[j] = true;
        }
    }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    sosu();
    while(1){
        int i=2;
        cin>>N;
        if(N==0) break;
        while(arr[i]|arr[N-i]){
            i++;
        }
        cout<<N<<" = "<<i<<" + "<<N-i<<'\n';
    }
    return 0;
}