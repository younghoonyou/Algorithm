#include <iostream>
#include <algorithm>
using namespace std;
int arr[21][21][21]={};
int w(int A,int B,int C){
    if(A<=0||B<=0||C<=0){
        return 1;
    }
    else if(A>20||B>20||C>20){
        return w(20,20,20);
    }
    else if(A<B&&B<C){
        if(arr[A][B][C]){
            return arr[A][B][C];
    }
        else    return arr[A][B][C] = w(A,B,C-1) + w(A,B-1,C-1) - w(A,B-1,C);
    }
    else{
        if(arr[A][B][C]){
            return arr[A][B][C];
    }
        else    return arr[A][B][C] = w(A-1,B,C) + w(A-1,B-1,C) + w(A-1,B,C-1) - w(A-1, B-1, C-1);
    }
}
int main(){
    int a,b,c;
    while(1){
        cin>>a>>b>>c;
        if(a==-1&&b==-1&&c==-1){
            break;
        }
        cout<<"w("<<a<<", "<<b<<", "<<c<<") ="<<" "<<w(a,b,c)<<endl;
    }
    return 0;
}