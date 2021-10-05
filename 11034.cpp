#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int N[3],mini,answer;
    while(1){
    for(int i=0;i<3;++i){
        cin>>N[i];
    }
    if(N[2]-N[1]>N[1]-N[0]){
        answer=N[2]-N[1]-1;
    }
    else{
        answer=N[1]-N[0]-1;
    }
    cout<<answer;
    }
    return 0;
}