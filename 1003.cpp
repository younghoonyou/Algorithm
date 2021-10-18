#include <iostream>
#include <stdio.h>
using namespace std;
int store[41]={0,1,};
int fibonacci(int n) {
    if (n == 0)
    {
        store[0] = 0;
        return store[0];   
    }
    if (n == 1)
    {
        store[1]=1;
        return store[1];
    }
    if(store[n]!=0){
        return store[n];
    }
        return store[n]= fibonacci(n-1) + fibonacci(n-2);

}
int main()
{
   int N,a;
    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
    scanf("%d",&a);
    if(a==0){
        printf("1 0\n");
    }
    else{
        printf("%d %d\n",fibonacci(a-1),fibonacci(a));
    } 
        // b=0;
        // c=0;
       }
    return 0;
   }

