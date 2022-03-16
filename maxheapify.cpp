#include <bits/stdc++.h> 
using namespace std;
void swap_(int *a,int *b)
{
    int *t;
    *t=*a;
    *a=*b;
    *b=*t;
}
void mxheap(int a[],int n)
{
   
    for(int i=1;i<n;i++ )
    { int temp=a[i],j=i;

        while(j>1&&temp>a[j/2])
        {
            a[j]=a[j/2];
            j=j/2;
        }
        a[j]=temp;
    }
}
void mnheap(int a[],int n)
{
    for(int i=1;i<n;i++ )
    { int temp=a[i],j=i;

        while(j>1&&temp<a[j/2])
        {
            a[j]=a[j/2];
            j=j/2;
        }
        a[j]=temp;
    }
}
void mxdelete(int a[],int n)
{
    int i=1,j=2*i,x=a[1];
    a[i]=a[n];
    while(j<n)
    {
        if(a[j+1]>a[j])
        {
            j=j+1;
        }
        if(a[j]>a[i])
        {
            swap_(&a[i],&a[j]);
            i=j;
        }
        else 
        break;
    }
    a[n]=x;
    return;
}
void mxheapsort(int a[],int n)
{
    for(int i=n-1;i>=1;i--)
    {
       mxdelete(a,i);
    }
   return;
}
int main()
{ 
   int n;
   scanf("%d",&n);
   int a[n+1],b[n+1];
   for(int i=1;i<n+1;i++)
    {a[i]=i;b[i]=i;}
    mxheap(a,n+1);
   mxheapsort(a,n+1);
   for(int i=1;i<n+1;i++)
   printf("%d ",a[i]);
   printf("\n");

}
