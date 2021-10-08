#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string str;
    int a[26] = {0,};
    cin>>str;
    int index;
    int temp=-1;
    for(char ch:str){
        ch = toupper(ch);
        a[ch  - 'A']++;
    }
    for(int i=0;i<26;++i){
        if(temp<a[i]){
            temp = a[i];
            index = i;
        }
    }
    for(int i=0;i<26;++i){
        if((temp==a[i])&&(i!=index)){
            cout<<"?"<<endl;
            return 0;
        }
    }
    cout << (char)(index+'A') << endl;
    return 0;
}