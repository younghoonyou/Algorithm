#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int x,y,w,h,answer;
    cin>>x>>y>>w>>h;
    answer = min(min(x,y),min(abs(x-w),abs(y-h)));
    cout<<answer;
    return 0;
}