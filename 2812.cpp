#include <iostream>
#include <string>
#include <deque>
using namespace std;
int N,del;
string str;
int main(){
    deque<char> deq;
    cin>>N>>del;
    cin>>str;
    for(int i=0;i<str.length();++i){
        while(del && !deq.empty() && deq.back()<str[i]){
            deq.pop_back();
            del--;
        }
        deq.push_back(str[i]);
    }
    if(del!=0) while(del--) deq.pop_back();
    while(!deq.empty()){
        cout<<deq.front();
        deq.pop_front();
    }
    cout<<'\n';
}//deque를 이용해서 O(n)으로 계산의 효율을 늘리고 하나씩 비교하면서 앞뒤로 push,pop