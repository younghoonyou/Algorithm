#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[4002][4002];
string str1,str2;
int LCS(string s1,string s2){
    int answer=0;
    s1='0'+s1;
    s2='0'+s2;
    int s1_len = s1.length();
    int s2_len = s2.length();
    for(int i=0;i<s1_len;++i){
        for(int j=0;j<s2_len;++j){
            if(i==0||j==0) dp[i][j]=0;
            else if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;//같으면 값에 추가
            else dp[i][j] = 0;//Long Common String이므로 Sequence가 아니면 0으로 초기화
            answer=max(answer,dp[i][j]);//최대 string 저장
        }
    }
    return answer;
}
int main(){
    cin>>str1>>str2;
    if(str1.length()>str2.length()) swap(str1,str2);
    cout<<LCS(str1,str2);
    return 0;
}