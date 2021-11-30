#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
vector<int> v;
struct cmp{
    bool
    operator()(int a,int b){
        if(abs(a)==abs(b)) return a>b;
        return abs(a)>abs(b);
    }
};
priority_queue<int , vector<int> , cmp > q;
int N,cnt=0;
int main(){
    int temp;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        if(temp==0){
            if(q.empty()){
                cout<<0<<'\n';
                continue;
            }
            cout<<q.top()<<'\n';
            q.pop();
            continue;
        }
        q.push(temp);
    }
    return 0;
}//우선순위 큐도 구조체를 이용해서 연산자 오버로딩을 통해서 원하는 대로 입출력이 가능한 것을 알자.