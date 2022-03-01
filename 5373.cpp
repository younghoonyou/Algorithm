#include <iostream>
#include <algorithm>
using namespace std;
int N;
char cube[4][4][7];//1 위 W, 2 아 Y, 3 앞 R, 4 뒤 O, 5 왼 G, 6 오 B
char tmp[6];
enum color{
    W=1,Y,R,O,G,B
}COL;
// void init(){
//     for(int i=1;i<=3;++i){
//         fill_n();
//     }
// }
int main(){
    for(COL i = W;i<=B;i++){
        cout<<i<<" ";
    }
    // for(auto i:c){
    //     cout<<i<<" ";
    // }
    // int num;
    // char dir,rot;
    // cin>>N;
    // for(int i=0;;){

    // }
    // fill_n(tmp,5,'W');
    // for(auto i:tmp){
    //     cout<<i<<" ";
    // }
    cout<<Y;
    return 0;
}