//	 The below commented functions are for your reference. If you want 
//	 to use it, uncomment these functions.

// int mstrcmp(const char a[], const char b[])
// {
// 	int i;
// 	for (i = 0; a[i] != '\0'; ++i) if (a[i] != b[i]) return a[i] - b[i];
// 	return a[i] - b[i];
// }

// void mstrcpy(char dest[], const char src[])
// {
// 	int i = 0;
// 	while (src[i] != '\0') { dest[i] = src[i]; i++; }
// 	dest[i] = src[i];
// }

// int mstrlen(const char a[])
// {
// 	int i;
// 	for (i = 0; a[i] != '\0'; ++i);
// 	return i;
// }
using namespace std;
#include <string>
#include <vector>
class Family{
    private:
        string name;
        int gender,distance,relation;
    public:
        Family *next = nullptr;
        Family(string _name,int _gender){
            name = _name;
            gender = _gender;
            next->next = nullptr;
        }
        Family(string _name,int _gender,int relation,string __name,Family *temp){
            while(temp->next->name!=__name){
                temp++;
            }
        }
};
void init(char initialMemberName[], int initialMemberSex)
{
    Family(initialMemberName,initialMemberSex);
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[])
{
    Family(newMemberName,newMemberSex,relationship,existingMemberName,next);
	return false;
}

int getDistance(char nameA[], char nameB[])
{
	return -1;
}

int countMember(char name[], int dist)
{
	return -1;
}

