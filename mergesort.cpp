#include<bits/stdc++.h>
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a[n],b[m],c[n+m];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    }
    int i=0,j=0,k=0;
    while(i<n&&j<m)
    {
        if(a[i]<=b[j])
        {
            c[k]=a[i];
            k++;
            i++;
        }
        else
        {
            c[k]=b[j];
            j++;
            k++;
        }
    }
    while(i<n)
    {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<m)
    {
        c[k]=b[i];
        k++;
        i++;
    }
    for(int i=0;i<m+n;i++)
    printf("%d ",c[i]);
}