#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,w,h,count=0;
    cin>>N;
    vector<int> temp(N);
    vector<pair<int,int> > person;
    for(int i=0;i<N;++i){
        cin>>w>>h;
        person.push_back(make_pair(w,h));
    } 
    for(int i=0;i<N;++i){
        for(int j=0;j<N;++j){
            if(person[i].first<person[j].first&&person[i].second<person[j].second){
                count++;
            }
        }
        cout<<count+1<<" ";
        count=0;
    }
    return 0;
}