#include <stdio.h>
struct test
{
    int good,bad;
};

void swap(struct test* a,struct test* b){
    struct test t;
    t.good = a->good;
    a->good = b->good;
    b->good = t.good;
}
int main(){
    struct test a={4,5},b={7,8};

    printf("%d %d\n",a.good,a.bad);
    swap(&a,&b);
    printf("%d %d\n",b.good,b.bad);
}