#include<stdio.h>
#include<stdlib.h>
struct node{
    int value;
    struct node* next;
}* first=NULL;
void insert(int val)
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    p->value=val;
    p->next=NULL;
    if(first==NULL)
    {
        first=p;
        return;
    }
    else
    {
        struct node*q=first;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=p;
        return;
    }
}
void display()
{
    struct node* q=first;
    printf("List of Elemets: ");
    while(q!=NULL)
    {
        printf("%d ",q->value);
        q=q->next;
    }
    printf("\n");
}
void reverse()
{
    struct node* prev= NULL;
    struct node* current=first;
    struct node* next= NULL;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    first=prev;
}
void fbs(struct node* source,struct node** frontref,struct node** backref);
struct node* sortedmerge(struct node* a,struct node* b);
void mergesort(struct node **headref)
{
    struct node *head= *headref;
    struct node* a;
    struct node* b;
    if(first==NULL||first->next==NULL)
    return;
    fbs(head,&a,&b);
    mergesort(&a);
    mergesort(&b);
    *headref= sortedmerge(a,b);
    
}
struct node* sortedmerge(struct node* a,struct node* b)
{
    struct node* result=NULL;
    if(a==NULL)
    return b;
    else if(b==NULL)
    return a;
    if(a->value<=b->value){
    result=a;
    result->next=sortedmerge(a->next,b);
    }
    else
    {
        result=b;
        result->next=sortedmerge(a,b->next);
    }
    return result;
}
void fbs(struct node* source,struct node** frontref,struct node** backref)
{
    struct node* fast;
    struct node* slow;
    slow=source;
    fast=source->next;
    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
    }
    *frontref=source;
    *backref=slow->next;
     slow->next=NULL;
}
void sortedinsert(struct node** headref,struct node* newnode);
void insertionsort(struct node **headref)
{
    struct node* sorted =NULL;
    struct node* current =NULL;
    while(current!=NULL)
    {
        struct node *next=current->next;
        sortedinsert(&sorted,current);
        current=next;
    }
    *headref=sorted;
}
void sortedinsert(struct node** headref,struct node* newnode)
{
    struct node* current;
    if(*headref==NULL || (*headref)->value >= newnode->value)
    {
        newnode->next=*headref;
        *headref=newnode;
    }
    else
    {
        current=*headref;
        while(current->next!=NULL && current->next->value < newnode->value)
        {
            current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
}
int main()
{
    while(1)
    {
      int n;
      printf("Enter your choice: ");
      scanf("%d",&n);
      if(n==1)
      {
          int m;
          printf("Enter the data you want to insert: ");
          scanf("%d",&m);
          insert(m);
      }
      if(n==2)
      {
          display();
      }
      if(n==3)
      {
          reverse();
      }
      if(n==4)
      {
          //mergesort(&first);
          insertionsort(&first);
      }
      if(n==5)
      {
        break;
      }
    }
    return 0;
}