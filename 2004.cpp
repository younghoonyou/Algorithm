#include <iostream>
#include <algorithm>
using namespace std;
long long tw(long long a) {
	long long cnt = 0;
	for (long long i = 2; a / i >= 1; i *= 2) 
		cnt += a / i;
	return cnt;
}
long long fi(long long a) {
	long long cnt = 0;
	for (long long i = 5; a / i >= 1; i *= 5) 
		cnt += a / i;
	return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n,m;
    long long two=0,five=0;
    cin>>n>>m;
    if(n==m||m==0||n==0){
        cout<<"0";
        return 0;
    }
    two = tw(n) - tw(n-m) - tw(m);
    five = fi(n) - fi(n-m) - fi(m);
    two<five ? cout<<two:cout<<five;
    return 0;
}
//nCm = n! / (n-m)! * m!
//범위 때문에 ㅣong long 주의