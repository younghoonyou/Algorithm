#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory.h>
#include <vector>
using namespace std;
int N,M,D;
int arr[16][16];
int temp[16][16];
int order[4];
int die = 0;
bool visit[16];
int tmp = 0;
int standard;
vector<pair<int,int> > enemy;

int Dist(int x,int y,int x_,int y_){
    return abs(x-x_) + abs(y-y_);
}

bool cmp(pair<int,int> a,pair<int,int> b){
    if(Dist(a.first,a.second,N+1,standard) == Dist(b.first,b.second,N+1,standard)) return a.first<b.first;
    return Dist(a.first,a.second,N+1,standard)<Dist(b.first,b.second,N+1,standard);
}

bool alive(){//적이 있는지 살피는 과정
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            if(temp[i][j]==1) return true;
        }
    }
    return false;
}

// void attack(){//가장 가까운 적 먼저 공격, 거리가 같은 적이 많으면 가장 왼쪽부터 처치한다. 즉, 적의 거리를 먼저 판단한 후에 가장 왼쪽의 적을 공격
//     bool flag = false;
//     for(int i=1;i<=M;++i){
//         if(temp[N+1][i]==2){
//             for(int j=N;j>=0;--j){
//                 for(int k=1;k<=M;++k){
//                     if(temp[j][k]==1){
//                         int dis = abs(j - (N+1)) + abs(k - i);
//                         if(dis<=D){tmp++,flag = true;break;}
//                     }
//                 }
//                 if(flag) break;
//             }
//         }
//         flag = false;
//     }
// }


void attack(){//가장 가까운 적 먼저 공격, 거리가 같은 적이 많으면 가장 왼쪽부터 처치한다. 즉, 적의 거리를 먼저 판단한 후에 가장 왼쪽의 적을 공격
    for(int i=1;i<=3;++i){
        standard = order[i];
        sort(enemy.begin(),enemy.end(),cmp); //하나의 기준으로 정렬한 뒤에 가까운 순으로 왼쪽부터 처리한다.
        for(int j=0;j<enemy.size();++j){
            if(Dist(enemy[j].first,enemy[j].second,N+1,order[i])>D) continue;
            temp[][] = 0;
            enemy.erase();

        }
    }
}


void enemy_move(){
    for(int i=1;i<=M;++i){
        for(int j=N-1;j>=0;--j){
            temp[j+1][i] = temp[j][i];
        }
    }
    for(int i=1;i<=M;++i){
        temp[1][i] = 0;
    }
}

void fight(){
    while(alive()){
        attack();
        enemy_move();
    }

}
void archer(int n){
    if(n==4){
        tmp = 0;
        memcpy(temp,arr,sizeof(arr));
        fight();
        die = max(die,tmp);
        return ;
    }
    for(int i=1;i<=M;++i){
        if(!visit[i]){
            visit[i] = true;
            order[n] = i;
            arr[N+1][i] = 2;
            archer(n+1);
            arr[N+1][i] = 0;
            visit[i] = false;
        }
    }
}
int main(){
    freopen("Text.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M>>D;
    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>arr[i][j];
            if(arr[i][j]==1) enemy.push_back({i,j});
        }
    }
    archer(1);
    cout<<die<<'\n';
    return 0;
}