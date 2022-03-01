#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N;
int arr[101][101];
int main(){
    cin>>N;
    for(int i=0;i<N;++i){
        int col,row;
        cin>>col>>row;
        for(int j=1;j<=col;++j){
            for(int k=1;k<=row;++k){
                cin>>arr[j][k];
                
            }
        }
    }
    return 0;
}