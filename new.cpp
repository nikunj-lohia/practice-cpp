// C++ program to rotate a matrix 
// by 90 degrees 
#include <bits/stdc++.h> 
using namespace std;
int main()
{ 
   int n;
   scanf("%d",&n);
   int a[n][n],b[n][n];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           a[i][j]=i+j;
       }
   }
   int k=n-1;
    for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           b[i][j]=a[j][k];
       }
       k--;
   }
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           printf("%d ",a[i][j]);
       }
       printf("\n");
   }
}
