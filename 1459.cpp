//https://www.acmicpc.net/problem/1459
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long X,Y,W,S,ans = 0;
int main(){
    cin>>X>>Y>>W>>S;
    ans+=min(X,Y)*min(2*W,S);
    1&abs(X-Y) ? ans+=((abs(X-Y)-1)*min(W,S)+W) : ans+=abs(X-Y)*min(W,S);
    cout<<ans;
    return 0;
}