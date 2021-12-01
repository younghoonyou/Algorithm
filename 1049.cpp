#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int six_arr[1001];
int each_arr[1001];
bool cmp(int a,int b){
    return a<b;
}
int main(){
    int N,M;
    int six,each;
    int sum = 0;
    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>six_arr[i];
        cin>>each_arr[i];
    }
    sort(six_arr,six_arr+M,cmp);
    sort(each_arr,each_arr+M,cmp);
    while(N!=0){
        if(N>=6){
            if(six_arr[0]>each_arr[0]*6){
                sum+=each_arr[0]*N;
                N=0;
            }
            else{
                sum+=six_arr[0];
                N-=6;
            }
        }
        else{
            if(six_arr[0]>each_arr[0]*N){
                sum+=each_arr[0]*N;
                N=0;
            }
            else{
                sum+=six_arr[0];
                N=0;
            }
        }
    }
    cout<<sum;
    return 0;
}