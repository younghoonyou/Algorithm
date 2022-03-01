#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N,temp;
    int total=0;
    vector<int> vec;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>temp;
        vec.push_back(temp);
    }
    sort(vec.begin(),vec.end());
    for(int i=0;i<N-1;i+=2){
        // if(vec[i]==0||vec[i]<0){
        //         if(vec[i]<0&&vec[i+1]<0){
        //         total+=vec[i]*vec[i+1];
        //         continue;
        //     }
        //     else if(vec[i]==0&&vec[i+1]<0){
        //         continue;
        //     }
        // total+=vec[i]+vec[i+1];
        // continue;
        // }
        // total+=vec[i]*vec[i+1];
        if(vec[i])
    }
    cout<<total<<endl;
    return 0;
}