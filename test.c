#include<stdio.h>
#include <stdlib.h>
int *reallocation(int a[],int r,int n)
{
    int* b=(int *)malloc(r*sizeof(int));
    for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    free(a);
    return b;
}
int main()
{ 
   int n,r,*b;
   scanf("%d%d",&n,&r);
   int a[n];
   for(int i=0;i<n;i++)
   scanf("%d",&a[i]);
   b= reallocation(a,r,n);
   for(int i=0;i<r;i++)
   printf("%d ",b[i]);
}