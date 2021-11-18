#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;
int arr[10][10];
bool ten[10][10];
bool check(int x,int y,int num){
    for(int i=0;i<9;++i){
        if(arr[x][i]==num){
            if(y==i){
                continue;
            }
            return false;
        }
        else if(arr[i][y]==num){
            if(x==i){
                continue;
            }
            return false;
        }
    }
    for(int i=(x/3)*3;i<(x/3)*3+3;++i){
        for(int j=(y/3)*3;j<(y/3)*3+3;++j){
            if(x==i&&y==j){
                continue;
            }
            if(arr[i][j]==num){
                return false;
            }
        }
    }
    return true;
}
void sdoku(int n){
    int x = n/9;
    int y = n%9;
    if(n==81){
        cout<<'\n';
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                cout<<arr[i][j]<<" ";
            }
            cout<<'\n';
        }
        exit(0);//경우의 수가 많을 경우 한가지만 출력하고 끝남
    }
        if(arr[x][y]==0){
            for(int j=1;j<=9;++j){
                if(check(x,y,j)){
                    arr[x][y] = j;
                    sdoku(n+1);
                    arr[x][y] = 0;
                }
            }
        }
        else{
            return sdoku(n+1);
        }
}
int main(){
    for(int i=0;i<9;++i){
        for(int j=0;j<9;++j){
            cin>>arr[i][j];
        }
    }
    sdoku(0);
    return 0;
}//접근법은 좋았으나 살짝 응용이 부족했다 백트래킹은 인셉션인거 기억하자