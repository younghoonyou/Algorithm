#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;//N극 0,S극 1
int tire[4][8];
bool compare[3];
void rotate_clock(int arr[8]){
    int temp = arr[7];
    for(int i=6;i>=0;--i){
        arr[i] = arr[i+1];
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
int main(){
    int K,num,circle,sum=0;
    string str;
    for(int i=0;i<4;++i){
        cin>>str;
        for(int j=0;j<str.length();++j){
            tire[i][j] = str[j] - '0';
        }
    }
    cin>>K;
    for(int i=0;i<K;++i){
        cin>>num>>circle;
        bool flag = false;
        memset(compare,false,sizeof(compare));
        if(tire[0][2]==tire[1][6]){
            compare[0] = false;
        }
        else compare[0] = true;

        if(tire[1][2]==tire[2][6]){
            compare[1] = false;
        }
        else compare[1] = true;

        if(tire[2][2]==tire[3][6]){
            compare[2] = false;
        }
        else compare[2] = true;
        if(circle==1){
            rotate_clock(tire[num-1]);
            flag = true;
        }
        else{
            rotate_reverse_clock(tire[num-1]);
            flag = false;
        }
    }
    for(int i=0;i<4;++i){
        if(tire[i][0]) sum+=pow(2,i);
    }
    cout<<sum;
    return 0;
}