#include <iostream>
#include <string>
#include <vector>
using namespace std;
int person(int floor,int room){
    if(room== 1){return 1;}
    if(floor == 0){return room;}
    return (person(floor-1,room)+person(floor,room-1));
}
int main(){
    int N,k,n,total=0;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>k;
        cin>>n;
        cout<<person(k,n)<<endl;
        }
        
    return 0;
}