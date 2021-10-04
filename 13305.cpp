#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
long long N,temp,total=0,min_val;
cin>>N;
long long km[N], price[N];
for(int i=0;i<N-1;++i){
    cin>>km[i];
}
for(int i=0;i<N;++i){
    cin>>price[i];
}
total+=km[0]*price[0];
min_val=price[0];
for(int i=1;i<N-1;++i){
    if(min_val<price[i]){
        total+=km[i]*min_val;
    }
    else{
        min_val=price[i];
        total+=km[i]*min_val;
    }
}
cout<<total;
return 0;
}