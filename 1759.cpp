#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int L,C;
char word[25];
char order[25];
bool v[25];
void sentence(int n,int k){
    if(n==L){
        int ja=0,mo=0;
        for(int t=0;t<L;++t){
            if(order[t]=='a' || order[t]=='e' || order[t]=='i' || order[t]=='o' || order[t]=='u') mo++;
            else ja++;
        }
        if(ja<2 || mo<1) return ;
        for(int i=0;i<L;++i){
            cout<<order[i];
        }
        cout<<'\n';
        return ;
    }
    for(int i=k;i<C;++i){
        if(!v[i]){
            v[i] = true;
            order[n] = word[i];
            sentence(n+1,i);
            v[i] = false;
        }
    }
}
int main(){
    cin>>L>>C;
    for(int i=0;i<C;++i){
        cin>>word[i];
    }
    sort(word,word+C);
    sentence(0,0);
    return 0;
}//문제를 잘 읽자 영훈아 제발~~~~~~~~~~~~~~~~~~