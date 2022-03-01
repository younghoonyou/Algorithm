#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;
int N,M,P;
long s[10];//이동 할 수 있는 범위
char arr[1001][1001];
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};
int answer[10];
int num=0;
queue<pair<int,int> > temp[10];//x,y,[n]
void bfs(int n){//플레이어 몇인지 고려해야 한다
    int cnt = s[n];
        while(!temp[n].empty()&&cnt--){
            int ts = temp[n].size();
            for(int i=0;i<ts;++i){
                int x = temp[n].front().first;
                int y = temp[n].front().second; 
                temp[n].pop();
                for(int j=0;j<4;++j){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(nx<=0 || ny<=0 || nx>N || ny>M || arr[nx][ny]!='.'||arr[nx][ny]=='#') continue;
                arr[nx][ny] = n + '0';
                temp[n].push({nx,ny});
                answer[n]++;
            }
            }
        }
}
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M>>P;
    for(int i=1;i<=P;++i){
        cin>>s[i];
    }
    for(int i=1;i<=N;++i){
        string str;
        cin>>str;
        for(int j=1;j<=M;++j){
            arr[i][j]=str[j-1];
            if(arr[i][j]=='#') num++;
            if(arr[i][j] >= '1' && arr[i][j] <= '9') temp[arr[i][j]-'0'].push({i,j}),answer[arr[i][j]-'0']++;
        }
    }
    while(1){
        for(int i=1;i<=P;++i){
            bfs(i);
        }
		bool finish = true;
		for (int i = 1; i <= P; i++) {
			if (!temp[i].empty()) {//모두 비어 있으면 움직 일 수 없으므로 탈출
				finish = false;
				break;
			}
		}
		if (finish) break;
    }
    for(int i=1;i<=P;++i){
        cout<<answer[i]<<" ";
    }
    cout<<'\n';
    return 0;
}


