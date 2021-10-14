#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,a;
    string str;
    cin>>N;
    deque<int> what;
    for(int i=0;i<N;++i){
        cin>>str;
        if(str=="push_back"){
            cin>>a;
            what.push_back(a);
        }
        else if(str=="push_front"){
            cin>>a;
            what.push_front(a);
        }
        else if(str=="front"){
            if(what.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<what.front()<<'\n';
            }
        }
        else if(str=="back"){
            if(what.empty()){
                cout<<-1<<'\n';
            }
            else{
                cout<<what.back()<<'\n';
            }
        }
        else if(str=="size"){
            cout<<what.size()<<'\n';
        }
        else if(str=="empty"){
            cout<<what.empty()<<'\n';
        }
        else if(str=="pop_back"){
            if(what.empty()){
                cout<<-1<<'\n';
            }
            else{
            cout<<what.back()<<'\n';    
            what.pop_back();
            }
        }
        else if(str=="pop_front"){
            if(what.empty()){
                cout<<-1<<'\n';
            }
            else{
            cout<<what.front()<<'\n';    
            what.pop_front();
            }
        }
    }
    return 0;
}