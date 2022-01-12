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
struct Family{
    string name;
    int distance,gender,relation;
};
vector<Family> person[200];
void init(char initialMemberName[], int initialMemberSex)
{
    for(int i=0;i<200;++i) person[i].clear();
    person[0].push_back({initialMemberName,0,initialMemberSex,-1});
}

bool addMember(char newMemberName[], int newMemberSex, int relationship, char existingMemberName[])
{
    
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

