#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<string> temp;
string str="";
int N;
int arr[10];
char buho[10];
bool v[10];

bool compare(int a,char b,int c){
    if(b == '<'){
        if(a<c) return true;
    }
    else{
        if(a>c) return true;
    }
    return false;
}
void bu(int n){
    if(n==N+1){
        for(int i=0;i<N+1;++i){
            // cout<<arr[i];
            str+=to_string(arr[i]);
        }
        temp.push_back(str);
        str.clear();
        // cout<<'\n';
    }
    if(n==0){
        for(int i=0;i<=9;++i){
            if(!v[i]){
                arr[n] = i;
                v[i] = true;
                bu(n+1);
                arr[n] = 0;
                v[i] = false;
            }
        }
    }
    else{
        for(int i=0;i<=9;++i){
        if(!v[i]){
            arr[n] = i;
            v[i] = true;
                if(compare(arr[n-1],buho[n],arr[n])){
                    bu(n+1);
                }
            v[i] = false;
            arr[n] = 0;
        }
    }
    }
}
int main(){
    cin>>N;
    for(int i=1;i<=N;++i){
        cin>>buho[i];
    }
    bu(0);
    cout<<temp[temp.size()-1]<<'\n';
    cout<<temp[0];
    return 0;
}