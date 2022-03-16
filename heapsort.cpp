#include<bits/stdc++.h>
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void mxheap(int a[],int n)
{
    for(int i=1;i<=n;i++)
    {
        int j=i,x=a[i];
        while(j>1&&x>a[j/2])
        { 
            a[j]=a[j/2];
            j=j/2;
        }
        a[j]=x;
    }
}
void deletemx(int a[],int n)
{
    int x=a[1];
    a[1]=a[n];
    int i=1,j=2*i;
    int k=n-1;
    while(j<k)
    {
        if(a[j]<a[j+1])
        {
            j=j+1;//comparing both childs
        }
        if(a[j]>a[i])
        {
            swap(&a[j],&a[i]);//swapping larger child with parent
            i=j;
            j=2*j;
        }
        else
        {
            break;
        }       
    }
    a[n]=x;
}
void printa(int a[],int n)
{
    int i=0;
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
  int a[11];
  for(int i=1;i<11;i++)
    a[i]=i;
    mxheap(a,10);
     for(int i=1;i<11;i++)
     printf("%d ",a[i]);
     printf("\n");
     for(int i=10;i>=1;i--)
     {
         deletemx(a,i);
        printa(a,10);
     }
}