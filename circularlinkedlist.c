#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
} *first=NULL;
void create(int a[],int n,struct node*q)
{
   struct node *last;
   q->data=a[0];
   q->next=NULL;
   	last=q;
   for(int i=1;i<n;i++)
   {
    struct node *p=(struct node*)(malloc(sizeof(struct node)));
   	p->data=a[i];
   	p->next=NULL;
   	last->next=p;
   	last=p;
   }
}
void display_circular(struct node *p)
{   struct node *q=p;
    do
    {
        printf("%d ",p->data);
        p=p->next;
    }
    while(p!=q);
}
void circular_del(int pos,int k)
{  struct node *p=first,*q=NULL;
   int i=pos;
   if(i<1||i>k)
    return ;
    if(pos==1)
    {
        while(p->next!=first)
        {
            p=p->next;
        }
        if(p==first)
        {
            free(first);
            first=NULL;
        }
        else{
        q=p->next;
        p->next=first->next;
        first=first->next;
        free(q);}

    }
    else{
        for(int i=0;i<pos-1;i++)
        {   q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
    }
}
void insert_circular(int pos,int val)
{  struct node *t=(struct node*)(malloc(sizeof(struct node))),*q=first;
   t->data=val;
   t->next=NULL;
    if(pos==0)
   {
       t->next=first;
       while(q->next!=first)
       {
           q=q->next;
       }
       q->next=t;
       first=t;
   }
   if(pos>0)
   {
       for(int i=0;i<pos-1;i++)
       {
           q=q->next;
       }
       t->next=q->next;
       q->next=t;
   }
}
int circular_length(struct node *p)
{   struct node *q=p;
    int ct=0;
    do{
     q=q->next;
     ct++;
    }while(q!=p);
    return ct;
}
int main()
{
    insert_circular(0,10);
    // insert_circular(1,19);
    // insert_circular(2,100);
    // insert_circular(3,103);
    // insert_circular(4,15);
    display_circular(first);
}
