#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long long maxi,mini;
bool v[1000001];
long long num[1000001]={0};

void sosu(){
    for(long long i=2;i*i<=maxi;++i){//시간초과 문제로 인해서 i*i를 이용
        long long q = mini/(i*i);
        if(mini%(i*i)!=0) q++;// Min범위에 들어가기 위한 조건
    
    while(q*(i*i)<=maxi){
        v[q*(i*i) - mini] = true;//Min을 이용해서 배열의 순서를 앞으로 당겨준다.
        q++;
        }
    }
}

int main(){
    cin>>mini>>maxi;
    long long cnt=maxi-mini+1;//전체에서 체크된 것만 빼준다.
    sosu();
    for(long long i=0;i<=maxi-mini+1;++i){
        if(v[i]) cnt--;
    }

    cout<<cnt;
}