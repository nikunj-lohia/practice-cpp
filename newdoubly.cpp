#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *next,*prev;
}*first=NULL;
void createdoubly(int a[],int n)
{  
    struct node *t=(struct node*)(malloc)(sizeof(struct node*));
    // cout<<"hi";
    struct node*p=first;
    if(first==NULL)
    {
        t->data=a[0];
        t->next=NULL;
        t->prev=NULL;
        first=t;
        p=first;
        // cout<<first->data<<" ";
    }
    for(int i=1;i<n;i++)
    {
        t=(struct node*)(malloc)(sizeof(struct node*));
        t->data=a[i];
        t->next=p->next;
        p->next=t;
        t->prev=p;
        p=t;
        // cout<<p->data<<" ";
    }
}
void insertdoubly(int n,int value)
{
    struct node *t,*p=first;
    if(n==0)
    {
        t=(struct node*)(malloc)(sizeof(struct node*));
        t->data=value;
        t->next=first;
        t->prev=NULL;
        first=t;
    }
    if(n>0)
    {
        t=(struct node*)(malloc)(sizeof(struct node*));
        t->data=value;
        while(n>0)
        {
            p=p->next;
            n--;
        }
        p->prev->next=t;
        t->next=p;
        t->prev=p->prev;
        p->prev=t;
    }
}
void deletedoubly(int n)
{   struct node*p=first;
    if(n==0)
    {
        first=first->next;
        first->prev=NULL;
        free(p);
    }
    if(n>0)
    { 
        while(n>0)
        {
            p=p->next;
            n--;
        }
        if(p->next!=NULL)
        { 
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        }
       if(p->next==NULL)
       {
        p->prev->next=NULL;
       }
    }
}
void printdoubly(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main()
{
    int a[4]={4,5,1,9};
    // first->next=first->prev=NULL;
    createdoubly(a,4);
    // printdoubly(first);
    deletedoubly(3);
    // insertdoubly(2,7);
    printdoubly(first);

    // cout<<first->data;
    // cout<<"jello;";
}
