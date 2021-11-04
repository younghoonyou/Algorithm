#include <iostream>
#include <algorithm>
using namespace std;
int arr[51];
int sub[50];
int main(){
    int N,b,maxi=0;
    double a;
    int zero=0;
    cin>>N;
    for(int i=0;i<N;++i){
        cin>>arr[i];
    }
    if(N==1){
        cout<<"A";
        return 0;
    }
    else if(N==2){
        if(arr[0]==arr[1]){
            cout<<arr[0];
            return 0;
        }
        cout<<"A";
        return 0;
    }
    else{
        for(int i=0;i<N-1;++i){
            sub[i] = arr[i+1] - arr[i];
            if(sub[0]==0){
                maxi|=sub[i];
                if(maxi!=0){
                    cout<<"B";
                    return 0;
                }
                zero++;
            }
        }
        if(zero==N-1){
            cout<<arr[0];
            return 0;
        }
        a = (double)sub[1]/sub[0];
        if(a==0){
            for(int i=1;i<N-1;++i){
                if(sub[i]!=0){
                    cout<<"B";
                    return 0;
                }
            }
            cout<<arr[N-1];
            return 0;
        }
        for(int i=1;i<N-2;++i){
            if(a!=(double)sub[i+1]/sub[i]){
                cout<<"B";
                return 0;
            }
        }
        b = arr[1] - a*arr[0];
        if((int)a-a!=0){
            cout<<"B";
            return 0;
        }
        cout<<arr[N-1]*a+b;
    }
    return 0;
}