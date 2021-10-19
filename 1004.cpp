#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
float dist(int a,int b, int c,int d){
return sqrt(pow(a-c,2)+pow(b-d,2));
}
int main(){
    int N,start[2],end[2];
    int first,second,radius;
    cin>>N;
    vector<int> count(N);
    int n;
    for(int i=0;i<N;++i){
        cin >> start[0] >> start[1] >> end[0] >> end[1];
        cin>>n;
        int stone[n][3];
        for(int j=0;j<n;++j){
            cin >> first >> second >>radius;
            stone[j][0] = first;
            stone[j][1] = second;
            stone[j][2] = radius;
        }
    for(int k=0;k<n;++k){
        if((dist(start[0],start[1],stone[k][0],stone[k][1])<stone[k][2])&&(dist(end[0],end[1],stone[k][0],stone[k][1])>stone[k][2])){
            count[i]++;
        }
        else if((dist(start[0],start[1],stone[k][0],stone[k][1])>stone[k][2])&&(dist(end[0],end[1],stone[k][0],stone[k][1])<stone[k][2])){
            count[i]++;
        }
    }
    }
    for(int i=0;i<N;++i){
        cout<<count[i]<<'\n';
    }
    return 0;
}