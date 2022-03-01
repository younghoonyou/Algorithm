#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int go[11];
int temp = 0;
int answer = -1;
bool visit[11];
int horse[32];
int point = 0;
int where[4];
vector<int> tmp[32];
void add(int a,int b){
    tmp[a].push_back(b);
}
void init(){
    for(int i=1;i<=19;++i) add(i,i+1);
    add(5,21),add(21,22),add(22,23),add(23,26);
    add(10,24),add(24,25),add(25,26);
    add(15,27),add(27,28),add(28,29),add(29,26);
    add(26,30),add(30,31),add(31,20);

    for(int i=1;i<=20;++i){
        horse[i] = i*2;
    }
    horse[21] = 13,horse[22] = 16,horse[23] = 19;
    horse[24] = 22,horse[25] = 24,horse[26] = 25;
    horse[27] = 28,horse[28] = 27,horse[29] = 26;
    horse[30] = 30,horse[31] = 35;
}
void play(int n){
    if(n){
        answer = max(answer,temp);
        return ;
    }
    for(int i=0;i<4;++i){
        if(!visit[i] && where[]){
            visit[i] = true;
            play(n+1);
            visit[i] = false;
        }
    }
}
int main(){
    for(int i=1;i<=10;++i){
        cin>>go[i];
    }
    init();
    play(1);
    cout<<answer;
    return 0;
}