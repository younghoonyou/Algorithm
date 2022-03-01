#include <iostream>
#include <algorithm>
using namespace std;
int N,Q;
int MUL(int n,int k){
    int sum = 1;
    for(int i=0;i<k;++i){
        sum*=n;
    }
    return sum;
}

void rotate(int start_x,int start_y,int end_x,int end_y){
        int temp = temp_arr[start_x][start_y];
        for(int i=start_x+1;i<=end_x;++i){//1번재 순환
            temp_arr[i-1][start_y] = temp_arr[i][start_y];
        }
        for(int i=start_y+1;i<=end_y;++i){//2번째 순환
            temp_arr[end_x][i-1] = temp_arr[end_x][i];
        }
        for(int i=end_x-1;i>=start_x;--i){//3번재 순환
            temp_arr[i+1][end_y] = temp_arr[i][end_y];
        }
        for(int i=end_y-1;i>=start_y+1;--i){//4번째 순환
            temp_arr[start_x][i+1] = temp_arr[start_x][i];
        }
        temp_arr[start_x][start_y+1] = temp;
}
void change(int n){
    rotate()
}

int main(){
    cin>>N>>Q;
    int range = MUL(2,N);
    for(int i=1;i<=range;++i){
        for(int j=1;j<=range;++j){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<Q;++i){
        int L;
        cin>>L;
        L = MUL(2,L);
        
        rotate();
    }
    return 0;
}