#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool store[81][3];
int temp[81];
int N;
int i=0;
void num(int n){
    if(n==N+1){
        cout<<temp[n-1]<<'\n';
        i++;
    }
        for(int j=1;j<=3;++j){
            if(store[n-1][j]) continue;
            temp[n] = 10*temp[n-1]+j;
            store[n][j] = true;
            store[n-1][j] = false;
            num(n+1);
            store[n][j] = false;
            store[n-1][j] = true;
        }
}
int main(){
    cin>>N;
    num(1);
    return 0;
}