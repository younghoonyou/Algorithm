#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int N,M;
char arr[51][51];
int white(){
    int x_idx=0;
    int answer =9876543;
    for(int y_idx = 0;y_idx<=M-8;++y_idx){
        int tmp = 0;
    for(int i=x_idx;i<x_idx+8;++i){
        for(int j=y_idx;j<y_idx+8;++j){
            if(1&(i+j)){
                if(arr[i][j]!='B') tmp++;
            }
            else{
                if(arr[i][j]!='W') tmp++;
            }
        }
    }
    answer = min(tmp,answer);
    if(y_idx==M-8&&x_idx==N-8) return answer;
    if(y_idx==M-8) x_idx++,y_idx=-1;
    }
    return answer;
}
int black(){
    int x_idx=0;
    int answer =9876543;
    for(int y_idx = 0;y_idx<=M-8;++y_idx){
        int tmp = 0;
    for(int i=x_idx;i<x_idx+8;++i){
        for(int j=y_idx;j<y_idx+8;++j){
            if(1&(i+j)){
                if(arr[i][j]!='W') tmp++;
            }
            else{
                if(arr[i][j]!='B') tmp++;
            }
        }
    }
    answer = min(tmp,answer);
    if(y_idx==M-8&&x_idx==N-8) return answer;
    // cout<<y_idx<<" ";
    if(y_idx==M-8) x_idx++,y_idx=-1;
    // cout<<y_idx<<" ";
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin>>N>>M;
    for(int i=0;i<N;++i){
        cin>>str;
        for(int j=0;j<str.length();++j){
            arr[i][j] = str[j];
        }
    }
    int answer = min(white(),black());
    cout<<answer<<'\n';
    return 0;
}