#include <iostream>
using namespace std;
int start,end;
int main(){
    int count=1;
    cin >> start >> end;
    while(1){
        if(start>end){
            cout<<-1<<endl;
            break;
        }
        if(start==end){
            cout<<count<<endl;
            break;
        }
        if(end%2==0){
                end/=2;
        }
        else if(end%10==1){
            end/=10;
        }
        else{
            cout<<-1<<endl;
            break;
        }
        count++;
    }
    return 0;
}