#include <iostream>
using namespace std;
double dist(int a,int b,int c, int d){
    return (a-c)*(a-c)+(b-d)*(b-d);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    int x1,y1,r1,x2,y2,r2;
    cin>>N;
    int answer[N];
    for(int i=0;i<N;++i){
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >>r2;
        if((dist(x1,y1,x2,y2)<(r1+r2)*(r1+r2))&&(dist(x1,y1,x2,y2)>(r1-r2)*(r1-r2))){
            cout<<"2"<<endl;
        }
        else if((dist(x1,y1,x2,y2)==(r1+r2)*(r1+r2))||(dist(x1,y1,x2,y2)==(r1-r2)*(r1-r2)&&(r1!=r2))){
            cout<<"1"<<endl;
        }
        else{
            if((dist(x1,y1,x2,y2)==0)&&(r1==r2)){
            cout<<"-1"<<endl;
        }else{
            cout << "0" << endl;
        }
        }
    }
    return 0;
}