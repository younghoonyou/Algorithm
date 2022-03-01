#include <algorithm>
#include <vector>
using namespace std;
struct Stock{
    int sNumber,sQuantity,sPrice;
};
bool buy_cmp(Stock &a,Stock &b){
    if(a.sPrice==b.sPrice){return a.sNumber>b.sNumber;}
        return a.sPrice<b.sPrice;
}
bool sell_cmp(Stock &a,Stock &b){
        if(a.sPrice==b.sPrice){return a.sNumber>b.sNumber;}
        return a.sPrice>b.sPrice;
};
vector<int> price_queue[6];
vector<Stock> buy_queue[6];
vector<Stock> sell_queue[6];
void init()
{   
    for(int i=1;i<=5;++i){
    buy_queue[i].clear();
    sell_queue[i].clear();
    price_queue[i].clear();
    }
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)
{
    if(sell_queue[mStock].size()==0){buy_queue[mStock].push_back({mNumber,mQuantity,mPrice});return mQuantity;}
    sort(sell_queue[mStock].begin(),sell_queue[mStock].end(),sell_cmp);
    int tmp =sell_queue[mStock].size();
    int num = sell_queue[mStock][tmp-1].sNumber;
    int quan = sell_queue[mStock][tmp-1].sQuantity;
    int price = sell_queue[mStock][tmp-1].sPrice;
    sell_queue[mStock].pop_back();
    if(mPrice>=price){
        if(quan<mQuantity){price_queue[mStock].push_back(price);return buy(mNumber,mStock,mQuantity-quan,mPrice);}
        else if(quan>mQuantity) sell_queue[mStock].push_back({num,quan-mQuantity,price});
        mQuantity=0;
        price_queue[mStock].push_back(price);
    }
    else{buy_queue[mStock].push_back({mNumber,mQuantity,mPrice});sell_queue[mStock].push_back({num,quan,price});}
    return mQuantity;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    if(buy_queue[mStock].size()==0){sell_queue[mStock].push_back({mNumber,mQuantity,mPrice});return mQuantity;}
    sort(buy_queue[mStock].begin(),buy_queue[mStock].end(),buy_cmp);
    int tmp = buy_queue[mStock].size();
    int num = buy_queue[mStock][tmp-1].sNumber;
    int quan = buy_queue[mStock][tmp-1].sQuantity;
    int price = buy_queue[mStock][tmp-1].sPrice;
    buy_queue[mStock].pop_back();
    if(mPrice<=price){
        if(quan<mQuantity){price_queue[mStock].push_back(price);return sell(mNumber,mStock,mQuantity-quan,mPrice);}
        else if(quan>mQuantity) buy_queue[mStock].push_back({num,quan-mQuantity,price});
        mQuantity=0;
        price_queue[mStock].push_back(price);
    }
    else{sell_queue[mStock].push_back({mNumber,mQuantity,mPrice});buy_queue[mStock].push_back({num,quan,price});}
    return mQuantity;
}

void cancel(int mNumber)
{
    for(int i=1;i<=5;++i){
        int sell_tmp = sell_queue[i].size();
        int buy_tmp = buy_queue[i].size();
        for(int j=0;j<sell_tmp;++j){
            int sell_num = sell_queue[i][j].sNumber;
            if(sell_num==mNumber){sell_queue[i].erase(sell_queue[i].begin()+j);return ;}
        }
        for(int j=0;j<buy_tmp;++j){
            int buy_num = buy_queue[i][j].sNumber;
            if(buy_num==mNumber){buy_queue[i].erase(buy_queue[i].begin()+j);return ;}
        }
    }
}

int bestProfit(int mStock){
int ans = 0;
    int tmp = price_queue[mStock].size();
    int res = price_queue[mStock][tmp-1];
    for(int i=tmp-2;i>=0;--i){
        int compare = price_queue[mStock][i];
        if(ans<res-compare){
            ans = res-compare;
        }
        if(compare>res){
            res = compare;
        }
}
    return ans;
}