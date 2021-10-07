#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct Person
    {
        int age;
        int index;
        string name;
    };
bool cmp(Person a,Person b){
    if(a.age==b.age){
        return a.index<b.index;
    }
    return a.age<b.age;
}
int main(){
    int N,age;
    string name;
    vector<Person> arr;
    Person person;
    cin>>N;
    for(int i=0;i<N;++i){
        cin >> person.age >> person.name;
        person.index = i;
        arr.push_back(person);
    }
    sort(arr.begin(),arr.end(),cmp);
    for(int i=0;i<arr.size();i++){
        cout << arr[i].age << " " << arr[i].name << '\n';
    }
    return 0;
}