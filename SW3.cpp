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
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
void init(int limit)
{
    cnt = limit;
}

void play()
{
    for (int r = 0; r < 10; ++r)
	for (int c = 0; c < 10; ++c)
		v[r][c] = false;
    int ship_cnt = 0;
    int fire_cnt = 0;
    for(int r=0;r<10;r++){
        int x;
        r&1 ? x=1:x=0;
        for(int c=x;c<10;c+=2){
            v[r][c] = true;
            int standard = fire(r,c);
            fire_cnt++;
            switch(standard){
                case MISS:{
                    continue;
                }
                default:{
                    int direction=99;
                    ship_cnt++;
                    std::queue<std::pair<int,int> > q;
                    q.push({r,c});
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int i=0;i<4;++i){
                            int nx = x + dx[i];
                            int ny = y + dy[i];
                            if(nx<0 || ny<0 || nx>9 || ny>9||v[nx][ny]) continue;
                            if(direction<4){
                                if((direction&1)!=(i&1)) continue;
                            }
                            int _fire = fire(nx,ny);
                            fire_cnt++;
                            v[nx][ny] = true;
                            if(fire_cnt>=cnt) return ;
                            if(_fire==0) continue;
                            _fire==standard ? direction=i:direction=99,standard=_fire;
                            ship_cnt++;
                            q.push({nx,ny});
                            if(ship_cnt==17) return ;
                        }
                    }
                }
            }        
        }
    }
}