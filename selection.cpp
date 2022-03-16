#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void selection(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        int p=i;
        for(int j=i;j<n;j++)
        {
            if(a[p]>a[j])
            p=j;
        }
        swap(&a[p],&a[i]);
    }
}
void insertion(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key=a[i];
        int j=i-1;
        while(key<a[j]&&j>-1)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void bubble(int a[],int n)
{
  for(int i=0;i<n-1;i++)
  {
      int flag=0;
      for(int j=0;j<n-i-1;j++)
      {
          if(a[j]>a[j+1])
          {
              swap(&a[j],&a[j+1]);
              flag=1;
          }
          if(flag==0)break;
      }
  }
}
void printa(int a[],int n)
{
    int i=0;
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[10];
    for(int i=0,j=10;i<10;i++,j--)
    {
        a[i]=rand();
    }
    bubble(a,10);
    printa(a,10);
     for(int i=0,j=10;i<10;i++,j--)
    {
        a[i]=rand();
    }
    selection(a,10);
    printa(a,10); 
    for(int i=0,j=10;i<10;i++,j--)
    {
        a[i]=rand();
    }
    insertion(a,10);
    printa(a,10);
}