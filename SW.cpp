#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_BUY 2
#define CMD_SELL 3
#define CMD_CANCEL 4
#define CMD_BEST_PROFIT 5

extern void init();
extern int buy(int mNumber, int mStock, int mQuantity, int mPrice);
extern int sell(int mNumber, int mStock, int mQuantity, int mPrice);
extern void cancel(int mNumber);
extern int bestProfit(int mStock);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mNumber, mStock, mQuantity, mPrice;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_BUY:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = buy(mNumber, mStock, mQuantity, mPrice);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        case CMD_SELL:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = sell(mNumber, mStock, mQuantity, mPrice);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        case CMD_CANCEL:
            scanf("%d", &mNumber);
            cancel(mNumber);
            break;
        case CMD_BEST_PROFIT:
            scanf("%d", &mStock);
            userAns = bestProfit(mStock);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Stock{
    int sNumber,sQuantity,sPrice;
};

struct Buy_cmp{
    bool operator()(Stock &a,Stock &b){
        if(a.sPrice==b.sPrice) return a.sNumber>b.sNumber;
        return a.sPrice<b.sPrice;
    }
};

struct Sell_cmp{
    bool operator()(Stock &a,Stock &b){
        if(a.sPrice==b.sPrice) return a.sNumber>b.sNumber;
        return a.sPrice>b.sPrice;
    }
};
queue<Stock> temp;
vector<int> price_queue[6];
priority_queue<Stock,vector<Stock>,Buy_cmp> buy_queue[6];
priority_queue<Stock,vector<Stock>,Sell_cmp> sell_queue[6];
void init()
{   
    while(!temp.empty()) temp.pop();
    for(int i=1;i<=5;++i){
    while(!buy_queue[i].empty()) buy_queue[i].pop();  
    while(!sell_queue[i].empty()) sell_queue[i].pop();
    price_queue[i].clear();
    }
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    if(sell_queue[mStock].empty()){buy_queue[mStock].push({mNumber,mQuantity,mPrice});return mQuantity;}
    int num = sell_queue[mStock].top().sNumber;
    int quan = sell_queue[mStock].top().sQuantity;
    int price = sell_queue[mStock].top().sPrice;
    sell_queue[mStock].pop();
    if(mPrice>=price){
        if(quan<mQuantity){price_queue[mStock].push_back(price);return buy(mNumber,mStock,mQuantity-quan,mPrice);}
        else if(quan>mQuantity) sell_queue[mStock].push({num,quan-mQuantity,price}),mQuantity=0;
        else mQuantity=0;
        price_queue[mStock].push_back(price);
    }
    else buy_queue[mStock].push({mNumber,mQuantity,mPrice}),sell_queue[mStock].push({num,quan,price});
    return mQuantity;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    if(buy_queue[mStock].empty()){sell_queue[mStock].push({mNumber,mQuantity,mPrice}); return mQuantity;}
    int num = buy_queue[mStock].top().sNumber;
    int quan = buy_queue[mStock].top().sQuantity;
    int price = buy_queue[mStock].top().sPrice;
    buy_queue[mStock].pop();
    if(mPrice<=price){
        if(quan<mQuantity){price_queue[mStock].push_back(price);return sell(mNumber,mStock,mQuantity-quan,mPrice);}
        else if(quan>mQuantity) buy_queue[mStock].push({num,quan-mQuantity,price}),mQuantity=0;
        else mQuantity=0;
        price_queue[mStock].push_back(price);
    }
    else sell_queue[mStock].push({mNumber,mQuantity,mPrice}),buy_queue[mStock].push({num,quan,price});
    return mQuantity;
}

void cancel(int mNumber)
{
    bool flag = false;
    for(int i=1;i<=5;++i){
        if(buy_queue[i].empty()) continue;
        while(!buy_queue[i].empty()){
            int num = buy_queue[i].top().sNumber;
            int quan = buy_queue[i].top().sQuantity;
            int price = buy_queue[i].top().sPrice;
            buy_queue[i].pop();
            if(num==mNumber){
                flag = true;
                break;
            }
            temp.push({num,quan,price});
        }
        while(!temp.empty()){
            int num = temp.front().sNumber;
            int quan = temp.front().sQuantity;
            int price = temp.front().sPrice;
            temp.pop();
            buy_queue[i].push({num,quan,price});
        }
        if(flag) return ;
    }
    for(int i=1;i<=5;++i){
        if(sell_queue[i].empty()) continue;
        while(!sell_queue[i].empty()){
            int num = sell_queue[i].top().sNumber;
            int quan = sell_queue[i].top().sQuantity;
            int price = sell_queue[i].top().sPrice;
            sell_queue[i].pop();
            if(num==mNumber){
                flag = true;
                break;
            }
            temp.push({num,quan,price});
        }
        while(!temp.empty()){
            int num = temp.front().sNumber;
            int quan = temp.front().sQuantity;
            int price = temp.front().sPrice;
            temp.pop();
            sell_queue[i].push({num,quan,price});
        }
        if(flag) return ;
    }
}

int bestProfit(int mStock){
int ans = 0;
    int tmp = price_queue[mStock].size();
    int res = price_queue[mStock][tmp-1];
    for(int i=tmp-2;i>=0;--i){
        int compare = price_queue[mStock][i];
        ans = max(ans,res-compare);
        if(compare>res){
            res = compare;
        }
}
    return ans;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("Text.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        if(score==MARK) printf("#%d %d\n", tc, score);
        // printf("#%d %d\n", tc, score);
    }

    return 0;
}