#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[100001];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,sang,answer;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    cin>>sang;
    sort(arr,arr+N);
        int start = 0;
        int end = arr[N-1];
        while(start<=end){
            int sum=0;
            int mid = (start + end)/2;
            for(int i=0;i<N;++i){
                sum+=min(mid,arr[i]);
            }
            if(sang>=sum){
                answer = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        cout<<answer;
    return 0;
}//이분탐색의 개념을 알면서 index가 아닌 value를 기준으로 전체 합이 상한가에 어떻게 적용되는지를 생각하자.