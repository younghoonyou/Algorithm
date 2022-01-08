//https://www.acmicpc.net/problem/1915
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N,M;
int answer = 0;
int arr[1000][1000];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for(int i=0;i<N;++i){
        string str;
        cin>>str;
        for(int j=0;j<M;++j){
            arr[i][j] = str[j] - '0';
            if(arr[i][j]==1) answer=1;
        }
    }
    for(int i=1;i<N;++i){
        for(int j=1;j<M;++j){
            if(arr[i][j]==1){
            arr[i][j] = 1+min({arr[i][j-1],arr[i-1][j-1],arr[i-1][j]});
            answer = max(answer,arr[i][j]);
            }
        }
    }
    answer*=answer;
    cout<<answer<<'\n';
}//https://donggoolosori.github.io/2020/12/20/pgmsquare/
//가장 큰 정사각형을 구하는 방법을 완전 다르게 생각할 수 있다