#include<iostream>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int answer=-1;//정답
    int start=1;
    int K,N;
    cin>>N>>K;
    int end = K;
    while(start<=end){
        long long cnt = 0;
        int mid = (start+end)/2;//중간
        for(int i=1;i<=N;++i) cnt+=min(N,mid/i);//총 mid보다 작은 원소의 갯수가 몇개인지
        if(cnt<K){//K번째를 넘기지 않았으면
            start = mid+1;
        }
        else{//K를 기준으로 넘었으면
            answer = mid;
            end = mid - 1;
        }
    }
    cout<<answer;
    return 0;
}// 각 행에서의 S보다 작거나 같은 숫자의 개수는 min(S / i, N) 
//K를 기준으로 조건에 따른 분할정복 이용