//https://www.acmicpc.net/problem/1476
#include <iostream>
using namespace std;
int main(){
    int a=1,b=1,c=1;
    int q,w,e;
    cin>>q>>w>>e;
    int cnt = 1;
    while(1){
        if(a==q&&b==w&&c==e) break;
        a++,b++,c++;
        if(a>15) a=1;
        if(b>28) b=1;
        if(c>19) c=1;
        cnt++;
    }
    cout<<cnt<<'\n';
    return 0;
}