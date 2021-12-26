#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int i = 666;
    for(;;i++){
        if(to_string(i).find("666")!=string::npos) n--;
        if(n==0) break;
    }
    cout<<i<<'\n';
    return 0;
}//완전탐색은 갯수를 고려해서 for문을 돌려도 된다.