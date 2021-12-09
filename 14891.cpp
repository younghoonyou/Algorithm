#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <memory.h>
using namespace std;
int tire[4][8];
bool v[4];
int sum=0;
void rotate_clock(int arr[8]){
    int temp = arr[7];
    for(int i=6;i>=0;--i){
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}
void rotate_reverse_clock(int arr[8]){
    int temp = arr[0];
    for(int i=0;i<7;++i){
        arr[i] = arr[i+1];
    }
    arr[7] = temp;
}
void turn(int n,int r){
    if(r==1) rotate_clock(tire[n]);
    else rotate_reverse_clock(tire[n]);
}
void compare(int n,int r){
    v[n] = true;
    int pn = n-1;
    int nn = n+1;
    if(pn>=0&&!v[pn]){
        if(tire[pn][2]!=tire[n][6]) compare(pn,-1*r);
    }
    if(nn<4&&!v[nn]){
        if(tire[nn][6]!=tire[n][2]) compare(nn,-1*r);
    }
    turn(n,r);
}
int main(){
    int N,num,rotate;
    string str;
    for(int i=0;i<4;++i){
        cin>>str;
        for(int j=0;j<8;++j){
            tire[i][j] = str[j] - '0';
        }
    }
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>num>>rotate;
        compare(num-1,rotate);
        memset(v,false,sizeof(v));
    }
    for(int i=0;i<4;++i){
        if(tire[i][0]) sum+=pow(2,i);
    }
    cout<<sum<<'\n';
    return 0;
}//각각 함수를 나눠서 생각했다. 그리고 방문을 기록하면서 함수 안에 함수를 넣는 방식으로 쪼갰다