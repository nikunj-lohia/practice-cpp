
#include<bits/stdc++.h>
struct node{
    int data;
    struct node* next;
}*first=NULL,*last=NULL;
void insert(int n,int value)
{
    struct node *t,*p=first,*q;
    t=(struct node*)(malloc(sizeof(node)));
        t->data=value;
        t->next=NULL;
    if(n==1)
    {
        t->next=first;
        first=t;
    }
    if(n>1)
    {
        while(n>1)
        {
            q=p;            
            p=p->next;
            n--;
        }
        q->next=t;
        t->next=p;
    }

}
void createlinkedlist(int a[],int n)
{

    struct node* t=(struct node*)malloc(sizeof(node));
    struct node *p;
    if(first==NULL)
    {
        t->data=a[0];
        t->next=t;
        first=t;
        p=first;
    }
    for(int i=1;i<n;i++)
    {

        t=(struct node*)malloc(sizeof(node));
        t->data=a[i];
        t->next=NULL;
        p->next=t;
        p=p->next;
    }
    last=p;
    p->next=first;
}

void deletelinkedlist(int n)
{   
    struct node* p=first,*q=NULL;
    if(n==0)
    {
        last->next=first->next;
        first=first->next;
        free(p);
    }
    while(n>0)
    {
        q=p;
        p=p->next;
        n--;
    }
    q->next=p->next;
    free(p);
}
void printlinkedlist(struct node *p)
{
    while(1)
    {
        printf("%d\n",p->data);
        p=p->next;
        if(p==last)break;
    }
}
int main()
{
  int a[4]={1,3,5,9};
  createlinkedlist(a,4);
  insert(2,4);
  printlinkedlist(first);
}