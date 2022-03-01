#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
int W,H,N;
int map[41][41];
struct Sticker{
    int x,y,val;
};
vector<Sticker> sticker[101];
bool check(int n){
    for(int i=0;i<sticker.size();++i){
        int curx = sticker[i].x;
        int cury = sticker[i].y;
        int cur_val = sticker[i].val;

    }
    return true;
}
void rotate(int n){

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>W>>H>>N;
    for(int i=0;i<N;++i){
        int s_w,s_h;
        cin>>s_w>>s_h;
        for(int j=0;j<s_w;++j){
            for(int k=0;k<s_h;++k){
                int tmp;
                cin>>tmp;
                sticker[i].push_back({j,k,tmp});
            }
        }
    }
    for(auto i:sticker){
        
    }
    return 0;
}