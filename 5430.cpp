#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
using namespace std;
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int N,arr_num;
    string temp,good;
    deque<int> ex;
    string str,array;
    cin>>N;
    if(N>100){
        return 0;
    }
    for(int i=0;i<N;++i){
        int count=0;
        bool flag = false;
        cin>>str;
        cin>>arr_num;
        cin>>array;
        array.erase(0,1);
        array.pop_back();
        istringstream ss(array);
        while(getline(ss,temp,',')){
            ex.push_back(stoi(temp));
        }
        for(char ch:str){
            if(ch=='R'){
                count++;
            }
            else if(ch=='D'){
                if(ex.empty()){
                    cout<<"error"<<'\n';
                    flag = true;
                    break;
                    }
                else{
                    if(count%2==0){
                        ex.pop_front();
                    }
                    else{
                        ex.pop_back();
                    }   
                }
            }
        }
        if(flag){continue;}
        if(arr_num!=0){
            if(count%2==0){
        for(int j=0;j<ex.size();++j){
            if(j==ex.size()-1){
                good+=to_string(ex[j]);
            }
            else{
                good+=to_string(ex[j]);
                good+=",";
            }
        }
            }
            else{
                for(int j=ex.size()-1;j>=0;--j){
            if(j==0){
                good+=to_string(ex[j]);
            }
            else{ 
                good+=to_string(ex[j]);
                good+=",";
            }
        }
            }
        }
            good.insert(0,"[");
            good+=']';
            cout<<good<<'\n';
            good.clear();
        ex.clear();
    }
    return 0;
}