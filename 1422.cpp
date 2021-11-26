#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
string arr[51];
bool cmp(string a,string b){
    if(a+b>b+a) return true;
    return false;
}//문자열 형식으로 사전 순으로 더했을 때 결과를 고려해서 나열하면 된다. ex) 9 89   89 9 전자가 더 크다
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
}//가장 큰 수를 해당하는 곳에 잘 넣으면 된다. 핵심은 위의 정렬 key point