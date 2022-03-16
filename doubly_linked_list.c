#include<stdio.h>
#include<stdlib.h>
struct node
{
 struct node *prev,*next;
 int data;
}*first=NULL;
void create(int a[],int n)
{
    struct node *last,*t;
    first=(struct node*)(malloc(sizeof(struct node)));
    first->data=a[0];
    first->next=first->prev=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {   t=(struct node*)(malloc(sizeof(struct node)));
        t->data=a[i];
        t->prev=last;
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
void display(struct node *p)
{  printf("The linked list is: ");
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
    return;
}
void insert_doubly_before(int pos,int val)
{
    struct node *t=(struct node*)(malloc(sizeof(struct node))),*p=first;
    t->data=val;
    t->next=t->prev=NULL;
        if(pos==0)
        {
            t->next=first;
            first->prev=t;
            first=t;
        }
        if(pos>0)
        {
            for(int i=0;i<pos-1;i++)
            {
                p=p->next;
            }
            t->next=p->next;
            t->prev=p;
            if(p->next!=NULL)
            p->next->prev=t;
            p->next=t;
        }
}
void insert_doubly_after(int pos,int val)
{
    struct node *t=(struct node*)(malloc(sizeof(struct node))),*p=first;
    t->data=val;
    t->next=t->prev=NULL;
        if(pos==0)
        {
            t->prev=first;
            t->next=first->next;
            if(first==NULL)
             {
                first=t;
             }
            if(first->next!=NULL)
            first->next->prev=t;
            first->next=t;
        }
        if(pos>0)
        {
            for(int i=0;i<pos;i++)
            {
                p=p->next;
            }
            t->next=p->next;
            t->prev=p;
            if(p->next!=NULL)
            p->next->prev=t;
            p->next=t;
            if(p->next==NULL)
            {
                p->next=t;
            }
        }
}
int main()
{
    int a[]={3,4,1,9,10};
    create(a,5);
    display(first);
    int n,m;
    printf("enter the node you want to insert before: ");
    scanf("%d",&n);
    printf("enter the value you want to insert: ");
    scanf("%d",&m);
    insert_doubly_before(n,m);
    display(first);

    printf("enter the node you want to insert before: ");
    scanf("%d",&n);
    printf("enter the value you want to insert: ");
    scanf("%d",&m);
    insert_doubly_before(n,m);
    display(first);

    printf("enter the node you want to insert before: ");
    scanf("%d",&n);
    printf("enter the value you want to insert: ");
    scanf("%d",&m);
    insert_doubly_before(n,m);
    display(first);

    printf("enter the node you want to insert after: ");
    scanf("%d",&n);
    printf("enter the value you want to insert: ");
    scanf("%d",&m);
    insert_doubly_after(n,m);
    display(first);

    printf("enter the node you want to insert after: ");
    scanf("%d",&n);
    printf("enter the value you want to insert: ");
    scanf("%d",&m);
    insert_doubly_after(n,m);
    display(first);

    printf("enter the node you want to insert after: ");
    scanf("%d",&n);
    printf("enter the value you want to insert: ");
    scanf("%d",&m);
    insert_doubly_after(n,m);
    display(first);  
}
