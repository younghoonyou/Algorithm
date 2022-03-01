#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,M;
vector<long> answer;
int arr[1025][1025];
int start_x,start_y;
int end_x,end_y;
int main(){
    int tmp;
    cin>>N>>M;
    cin>>arr[1][1];
    for(int i=1;i<=N;++i){
        for(int j=2;j<=N;++j){
            cin>>tmp;
            if()
            else arr[i][j] = arr[i][j-1] + tmp;
        }
    }
    for(int i=0;i<M;++i){
        long sum = 0;
        cin>>start_x>>start_y>>end_x>>end_y;
        for(int i=start_x;i<=end_x;++i){
            for(int j=start_y;j<=end_y;++j){
                sum+=arr[i][j];
            }
        }
        answer.push_back(sum);
    }
    for(auto i:answer){
        cout<<i<<'\n';
    }
    return 0;
}