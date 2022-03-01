#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
using namespace std;
int N,out=0,score=0;
int person[51][9];
bool home[4];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=9;++j){
            cin>>person[i][j];
        }
    }
    sort(person[1],person[1]+9,cmp);
    return 0;
}