#include <iostream>
using namespace std;
int main(){
    int N;
    int scount=0,lcount=0,total;
    cin>>N;
    char str[N];
    for(int i=0;i<N;++i){
        cin>>str[i];
        if(str[i]=='S'){
            scount++;
        }
        else if(str[i]=='L'){
            lcount++;
        }
    }
    if(lcount>0){
        lcount=(lcount/2)+1;
    }
    total=scount+lcount;
    cout<<total<<endl;
    return 0;
}