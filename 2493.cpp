#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,a;
    cin>>N;
    stack<pair<int,int> > temp;
    for(int i=1;i<=N;++i){
        cin>>a;
            while(!temp.empty()){
                if(temp.top().second>a){
                    cout<<temp.top().first<<" ";
                    break;
                }
                temp.pop();
            }
            if(temp.empty()){
            cout<<"0 ";
        }
        temp.push(make_pair(i,a));
    }
    for(int i=0;i<temp.size();++i){

    }
    return 0;
}
//스택을 이용해서 O(N^2)말고 pop()을 통해서 가장 큰 것과 이전 것만 비교한다. 나머지는 pop()으로 개수를 줄여준다.