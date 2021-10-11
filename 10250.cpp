#include <iostream>
using namespace std;
int main(){
    int N,w,h,n,answer;
    cin>>N;
    for(int i=0;i<N;++i){
        cin >> w >> h >> n;
        if(n%w==0){
            cout<< ((n-1)%w+1)*100+(n/w)<<endl;
        }
        else{
            cout<< (n%w)*100+(n/w + 1)<<endl;
        }
    }
    return 0;
}