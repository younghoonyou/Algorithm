#define MISS		0
#define CARRIER		1
#define BATTLESHIP	2
#define CRUISER		3
#define SUBMARINE	4
#define DESTROYER	5
#include <queue>
extern int fire(int r, int c);
bool v[10][10];
int cnt;
const int dx[] = {1,0,-1,0};//짝 세로 홀 가로
const int dy[] = {0,1,0,-1};
void init(int limit)
{
    cnt = limit;
}

void play()
{
    int cntt = 0;
    for (int r = 0; r < 10; ++r)
	for (int c = 0; c < 10; ++c)
		v[r][c] = false;

    int tmp = 0;
    for(int r=0;r<10;r++){
        int x;
        r&1 ? x=0:x=1;
        for(int c=x;c<10;c+=2){
            v[r][c] = true;
            int standard = fire(r,c);
            tmp++;
            switch(standard){
                case MISS:{
                    continue;
                }
                default:{
                    cntt++;
                    int index=98765;//방향
                    std::queue<std::pair<int,int> > q;
                    q.push({r,c});
                    while(!q.empty()){
                        // int index=98765;//방향
                        int x = q.front().first;
                        int y = q.front().second;
                        // printf("|%d %d|\n",x,y);
                        q.pop();
                        for(int i=0;i<4;++i){
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx<0 || ny<0 || nx>=10 || ny>=10||v[nx][ny]) continue;
                            if(fire(nx,ny)==0) continue;
                            // if(index<4){//
                            //     if((i&1)!=(index&1)) continue;
                            // }
                            // if(standard!=fire(nx,ny)){index = i;continue;}//
                            // if(standard!=fire(nx,ny)) continue;
                            // {printf("|X:%d Y:%d index:%d|\n",x,y,i);continue;}
                            v[nx][ny] = true;
                            q.push({nx,ny});
                            fire(nx,ny);
                            cntt++;
                            tmp++;
                        }
                    }
                }
            }
            if(tmp==cnt||cntt==17){printf("limit");return ;}
        }
    }
    printf("%d ",cntt);
}



// int main()
// {
// 	int TC;
	
//     freopen("test.txt", "r", stdin);

// 	setbuf(stdout, NULL);
//     scanf("%d", &TC);

// 	int totalscore = 0, totalcallcount = 0;
//     for (int testcase = 1; testcase <= TC; ++testcase)
// 	{
// 		int score = 100, callcount4tc = 0;
		
// 		scanf("%d %d", &seed, &limit);
// 		init(limit);

// 		for (int game = 0; game < 10; ++game)
// 		{
// 			doarrangment();
		
// 			hit = 0;
// 			for (int k = 0; k < 5; ++k)//len[5] = { 5, 4, 3, 3, 2 };
// 				hit += len[k];
		
// 			callcount = 0;
// 			play();

// 			if (hit != 0)
// 				callcount = MAX_CALLCOUNT;
			
// 			if (callcount > limit)
// 				score = 0;

// 			callcount4tc += callcount;
// 		}
		
// 		printf("#%d %d %d\n", testcase, score, callcount4tc);

// 		totalscore += score;
// 		totalcallcount += callcount4tc;
//     }
// 	printf("total score = %d, total callcount = %d\n", totalscore / TC, totalcallcount);
//     return 0;
// }