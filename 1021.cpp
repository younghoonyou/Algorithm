#include <iostream>
#include <deque>
#include <cmath>
#include <vector>
using namespace std;
int arr[51];
int main(){
    int N,num,count=0;
    cin>>N>>num;
    deque<int> temp;
    for(int i=1;i<=N;++i){
        temp.push_back(i);
    }
    for(int i=0;i<num;++i){
        cin>>arr[i];
    }
    for(int i=0;i<num;++i){
        int front = temp.front();
        int back = temp.back();
        int left=0,right=0;
        while(arr[i]!=front){
            temp.pop_front();
            temp.push_back(front);
            front = temp.front();
            left++;
        }
        for(int j=0;j<left;++j){
            back = temp.back();
            temp.push_front(back);
            temp.pop_back();
        }
        front = temp.front();
        back = temp.back();
        while(arr[i]!=front){
            temp.pop_back();
            temp.push_front(back);
            back = temp.back();
            front = temp.front();
            right++;
        }
        for(int j=0;j<right;++j){
            front = temp.front();
            temp.push_back(front);
            temp.pop_front();
        }
        front = temp.front();
        back = temp.back();
        if(right>=left){
            while(arr[i]!=front){
            temp.pop_front();
            temp.push_back(front);
            front = temp.front();
            }
            temp.pop_front();
            count+=left;
            // cout<<"Left:"<<left<<endl;
        }
        else{
            while(arr[i]!=front){
            temp.pop_back();
            temp.push_front(back);
            back = temp.back();
            front = temp.front();
            }
            temp.pop_front();
            count+=right;
            // cout<<"Right:"<<right<<endl;
        }

    }
    cout<<count;
    return 0;
}