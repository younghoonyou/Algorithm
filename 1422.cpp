#include <iostream>
#include <algorithm>
#include <string>
#include <memory.h>
using namespace std;
typedef long long ll;
string arr[51];
string answer[51];
bool cmp(string a,string b){
    if(a+b>b+a) return true;
    return false;
}
int main(){
    int n,k;
    string answer="";
    string maxi="";
    cin>>n>>k;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    sort(arr,arr+n,cmp);
    for(int i=0;i<n;++i){
        if(maxi.length()<arr[i].length()){
            maxi = arr[i];
        }
        else if(maxi.length() == arr[i].length()){
            if(stoll(maxi)<stoll(arr[i])){
                maxi = arr[i];
            }
        }
    }
    int index=0;
    for(int i=0;i<n;++i){
        if(maxi==arr[i]){
            index +=arr[i].length();
             break;
        }
        index += arr[i].length();
    }
    for(int i=0;i<n;++i){
        answer+=arr[i];
    }
    for(int i=0;i<k-n;i++){
        answer.insert(index,maxi);
    }
    cout<<answer;
}