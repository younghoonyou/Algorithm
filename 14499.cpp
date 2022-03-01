//https://www.acmicpc.net/problem/14499
#include <iostream>
#include <algorithm>
using namespace std;
int N,M,num;
int dice_direction = 0;
int map_x,map_y;
int arr[20][20];
int dicenum[7];
int MV[1000];
int direction;
int dice[7];// = {0,1,2,3,4,5,6};//앞 위 오 왼 아 뒷;
void roll_west(){//2
    int temp = dice[1];
    dice[1] = dice[3];
    dice[3] = dice[6];
    dice[6] = dice[4];
    dice[4] = temp;
}
void roll_east(){//1
    int temp = dice[1];
    dice[1] = dice[4];
    dice[4] = dice[6];
    dice[6] = dice[3];
    dice[3] = temp;
}
void roll_north(){//3
    int temp = dice[1];
    dice[1] = dice[5];
    dice[5] = dice[6];
    dice[6] = dice[2];
    dice[2] = temp;
}
void roll_south(){//4
    int temp = dice[1];
    dice[1] = dice[2];
    dice[2] = dice[6];
    dice[6] = dice[5];
    dice[5] = temp;
}
void play(int direction){
    switch (direction)
    {
    case 1:
        if(map_y+1>=M) break;
        roll_east();
        map_y++;
        if(arr[map_x][map_y]==0) arr[map_x][map_y] = dice[6];
        else dice[6] = arr[map_x][map_y],arr[map_x][map_y]=0;
        cout<<dice[1]<<'\n';
        break;
    case 2:
        if(map_y-1<0) break;
        roll_west();
        map_y--;
        if(arr[map_x][map_y]==0) arr[map_x][map_y] = dice[6];
        else dice[6] = arr[map_x][map_y],arr[map_x][map_y]=0;
        cout<<dice[1]<<'\n';
        break;
    case 3:
        if(map_x-1<0) break;
        roll_north();
        map_x--;
        if(arr[map_x][map_y]==0) arr[map_x][map_y] = dice[6];
        else dice[6] = arr[map_x][map_y],arr[map_x][map_y]=0;
        cout<<dice[1]<<'\n';
        break;
    case 4:
        if(map_x+1>=N) break;
        roll_south();
        map_x++;
        if(arr[map_x][map_y]==0) arr[map_x][map_y] = dice[6];
        else dice[6] = arr[map_x][map_y],arr[map_x][map_y]=0;
        cout<<dice[1]<<'\n';
        break;
    }
}

int main(){
    cin>>N>>M>>map_x>>map_y>>num;
    for(int i=0;i<N;++i){
        for(int j=0;j<M;++j){
            cin>>arr[i][j];
        }
    }
    dice[6] = arr[map_x][map_y];
    for(int i=0;i<num;++i){
        cin>>MV[i];
        play(MV[i]);
    } 
    return 0;
}//듣던 빡구현 문제 그냥 구현을 잘하는것도 능력