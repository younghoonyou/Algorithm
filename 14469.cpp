#include <iostream>
using namespace std;
int main(){
    char input;
    cin>>input;
    if(isalpha(input)){
        cout<<input-'A'+10;
    }
    else{
        cout<<input;
    }
    return 0;
}