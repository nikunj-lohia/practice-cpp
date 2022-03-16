#include<stdlib.h>
#include<stdio.h>
int max(int a,int b)
{
    if(a>b)
    return a;
    else 
    return b;
}
int main()
{
    int p1[100],t1[100],p2[100],t2[100];
    for(int i=0;i<100;i++)
    {
        p1[i]=0;
        t1[i]=0;
        p2[i]=0;
        t2[i]=0;
    }
    int n1,n2;
    scanf("%d",&n1);
    while(n1--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        //p1[b]=1;
        t1[b]=a;
    }
    scanf("%d",&n2);
    while(n2--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        p2[b]=1;
        t2[b]=a;
    }
    int f=1;
    for(int i=99;i>=0;i--)
    {   
        if(f==1)
        {   
            if(i==0)
            {
                if(t1[i]!=0||t2[i]!=0)
                {
                  printf("%d",t1[i]+t2[i]);  
                  f=0;
                }
            }
            else if(t1[i]!=0||t2[i]!=0)
            {
              printf("%dX^%d",t1[i]+t2[i],i);  
              f=0;
            }
    
        }
        else
        {
            if(i==0)
            {
                if(t1[i]!=0||t2[i]!=0)
                {
                  printf("+%d",t1[i]+t2[i]);  
                }
            }
             else if(t1[i]!=0||t2[i]!=0)
            {
              printf("+%dX^%d",t1[i]+t2[i],i);  
            }
            
        }
    }
}