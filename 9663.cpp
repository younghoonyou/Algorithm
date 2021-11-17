#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int where[16];
int total=0;
bool check(int n){
    for(int i=0;i<n;++i){
        if(where[i]==where[n]||abs(where[n]-where[i])==n-i){
           return false; 
        }
    }
    return true;
}
void nqueen(int n){
    if(n==N){
        total++;
        // for(int i=0;i<N;++i){
        //     cout<<where[i]<<" ";
        // }
        // cout<<'\n';
        return;
    }
    for(int i=0;i<N;++i){
        where[n] = i;
        if(check(n)) nqueen(n+1);
    }
}

int main(){
    cin>>N;
    nqueen(0);
    cout<<total;
    return 0;
}//2차원으로 생각하지 않고 인덱스를 이용해서 중복을 피하면서 2차원 배열처럼 생각할 수 있는 것이 레전드 풀이법...어렵다
//백트래킹 접근으로 2차원적으로 생각 할 수 있다.