#include <vector>
struct Stock
{
    int sNumber,sQuantity,sPrice;
};
void swap(Stock &a,Stock &b){
    Stock temp;
    temp.sNumber = a.sNumber;
    temp.sPrice = a.sPrice;
    temp.sQuantity = a.sQuantity;
    a.sNumber = b.sNumber;
    a.sPrice = b.sPrice;
    a.sQuantity = b.sQuantity;
    b.sNumber = temp.sNumber;
    b.sPrice = temp.sPrice;
    b.sQuantity = temp.sQuantity;
}
vector<Stock> market[6];
Stock buy_index={0,0,0},sell_index={0,0,0};
int buy_num,sell_num;

void init()
{

}

int buy(int mNumber, int mStock, int mQuantity, int mPrice)//
{
    if(market[mStock].empty()) market[mStock].push_back({mNumber,mQuantity,mPrice});

    return 0;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice)
{
    if(market[mStock].empty()) market[mStock].push_back({mNumber,mQuantity,mPrice});
    return 0;
}

void cancel(int mNumber)
{
}

int bestProfit(int mStock)
{
    return 0;
}