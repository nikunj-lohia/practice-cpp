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
void delete(int value)
{ 
    struct node *p=first,*q=NULL;
    while(p!=NULL)
    {

        if(p->data==value)
        {
            if(p==first)
            {
                first=p->next;
                p->next->prev=NULL;
                free(p);
            }
            else
            {
                p->prev->next=p->next;
                if(p->next==NULL)
                {
                    free(p);
                }
                else
                {
                    p->next->prev=p->prev;
                    free(p);
                }
            }
            break;
        }
        p=p->next;
    }
  return;  
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

int main()
{
    int a[]={3,4,1,9,10};
    create(a,5);
    display(first);
    int n;
    printf("enter the value you want to delete: ");
    scanf("%d",&n);
    delete(n);
    display(first);
}
