#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*first=NULL;
void insert_after(int n,int value)
{
    struct node *t,*p=first,*q;
    t=(struct node*)(malloc(sizeof(struct node)));
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
            p=p->next;
            n--;
        }
        t->next=p->next;
        p->next=t;
    }
}
void insert_before(int n,int value)
{
    struct node *t,*p=first,*q;
    t=(struct node*)(malloc(sizeof(struct node)));
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

    struct node* t=(struct node*)malloc(sizeof(struct node));
    struct node *p;
    if(first==NULL)
    {
        t->data=a[0];
        t->next=NULL;
        first=t;
        p=first;
    }
    for(int i=1;i<n;i++)
    {

        t=(struct node*)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        p->next=t;
        p=p->next;
    }
}

void deletelinkedlist(int n)
{   
    struct node* p=first,*q=NULL;
    if(n==1)
    {
        first=first->next;
        free(p);
    }
    if(n>1)
    {
        while(n>1)
        {
            q=p;
            p=p->next;
            n--;
        }
        q->next=p->next;
        free(p);
    }
}
void printlinkedlist(struct node *p)
{  printf("the linked list is: ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main()
{
  int a[4]={1,3,5,9};
  createlinkedlist(a,4);
  insert_before(1,4);
  insert_after(1,-1);
  printlinkedlist(first);
  deletelinkedlist(6);
  printlinkedlist(first);
   deletelinkedlist(1);
  printlinkedlist(first);
  insert_after(4,-1);
  printlinkedlist(first);
   insert_before(5,4);
  printlinkedlist(first);
}