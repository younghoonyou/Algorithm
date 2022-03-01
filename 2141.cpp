#include <iostream>
#include <algorithm>
using namespace std;
int town[100001];
int people[100001];
int post_pick[100001];
int N;
int post = 1;
int i=1;
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>town[i]>>people[i];
        if(i==1){
            post_pick[i] = 0;
            continue;
        }
        // post_pick[i] = post_pick[i-1]+(town[i] - town[i-1])*people[i-1];
    }
    for(int i=2;i<=N;++i){
        // if(post_pick[post] + (town[i]-town[post])*people[i]>post_pick[i]) post = i;
    }
    cout<<post<<'\n';
    return 0;
}