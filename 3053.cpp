#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    int r;
    double pi = M_PI;
    scanf("%d",&r);
    printf("%.6f\n",(double)pi*r*r);
    printf("%.6f\n",(double)r*r*2);
    return 0;
}