#include<iostream>
#include<algorithm>
using namespace std;
int N,M,B;
int low=99999999,high=0;
int arr[501][501];
int answer=99999999,height=0;
bool cmp(int a,int b){
    return a>b;
}
void minecraft(){
    for(int block=low;block<=high;++block){
        int time=0;
        int cnt=B;
        for(int i=0;i<N;++i){
            sort(arr[i],arr[i]+N,cmp);
            bool flag=false;
            for(int j=0;j<M;++j){
                cout<<arr[i][j]<<" ";
                // if(cnt==0){
                //     flag = true;
                //     break;
                // }
                if(block==arr[i][j]) continue;
                if(block>arr[i][j]){
                    time++,cnt--;
                    if(cnt<0){
                        flag = true;
                        break;
                    }
                    }
                else time+=2*(arr[i][j]-block),cnt+=arr[i][j]-block;
            }
            cout<<'\n';
            if(flag) break;
        }
        // cout<<time<<'\n';
        if(answer>time){
                    answer = time;
                    if(height<block) height = block;
                }
    }
}
int main(){
    cin>>N>>M>>B;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>arr[i][j];
            if(low>arr[i][j]) low = arr[i][j];
            if(high<arr[i][j]) high = arr[i][j];
        }
    }
    minecraft();
    cout<<answer<<" "<<height;
    return 0;
}
//높은 순서로 정렬, 파면 블록 1추가 시간2추가, 추가하면 블록 1감소 시간1추가
//완전탐색으로 검색