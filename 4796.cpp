#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int L,P,V,answer;
    int i=1;
    while(1){
        cin>>L>>P>>V;
        if(L==0&&P==0&&V==0){
            break;
        }
        answer=L*(V/P)+min((V%P),L);
        cout<<"Case "<<i<<": "<<answer<<endl;
        i++;
    }
    return 0;
}