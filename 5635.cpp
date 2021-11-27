#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
class Person{
    public:
    string name;
    int year,month,day;
};
bool cmp(Person &a,Person &b){
    if(a.year==b.year){
        if(a.month==b.month){
            if(a.day==b.day){
                return a.name<b.name;
            }
            return a.day<b.day;
        }
        return a.month<b.month;
    }
    return a.year<b.year;
}
int main(){
    int N;
    cin>>N;
    vector<Person> person(N);
    for(int i=0;i<N;++i){
        cin>>person[i].name>>person[i].day>>person[i].month>>person[i].year;
    }
    sort(person.begin(),person.end(),cmp);
    cout<<person[N-1].name<<'\n';
    cout<<person[0].name;
    return 0;
}