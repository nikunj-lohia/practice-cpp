#include<stdio.h>
#include <stdlib.h>
int  fibo(int f[],int n)
{
    if(n==0||n==1)
    {
        f[0]=0;
        f[1]=1;
    }
     else
    {
        f[n]=fibo(f,n-1)+fibo(f,n-2);
    }
    return f[n];
    
}
int main()
{ 
   int n;
   scanf("%d",&n);
   int f[n];
   int p=fibo(f,10);
   printf("%d",p); 
}