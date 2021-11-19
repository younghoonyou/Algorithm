#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string a;
int arr[22];
int answer[22]={0,};
bool v[22];
int N,S;
int s;
int ind = 0;
int what(int n){
    int sum;
    for(int i=1;i<=n;++i){
        sum+=i;
    }
    return sum;
}
void sum(int n){
    for(int i=n;i<=N;++i){
        if(!v[i]&&ind<i){
            v[i] = true;
            answer[n] += answer[n-1] + arr[i];
            if(answer[n]==S) a+="A";
            ind = i;
            sum(n+1);
            ind=0;
            answer[n] -= (answer[n-1] + arr[i]);
            v[i] = false;
        }
    }
}
int main(){
    cin>>N>>S;
    for(int i=1;i<=N;++i){
        cin>>arr[i];
    }
    // sort(arr,arr+N);
    sum(1);
    cout<<a.size();
    return 0;
}
//좀 더럽다 전역변수로 더할 수 있으면 좋겠는데 그게 안되서 그냥 string 길이로 했다.