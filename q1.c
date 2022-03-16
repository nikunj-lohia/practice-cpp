#include<stdio.h>
#include<stdlib.h>
#define ll long long int

#define siz 100000
ll front,rear,queue[100000];

void enqueue(ll num)
{
    if(rear==siz-1){
        printf("\nQueue full\n");
        return;
    }
    if(front==-1)
        front++;
    rear++;
    queue[rear]=num;
}

void deque()
{
    if(front==-1)
    {
        printf("\nQueue Empty\n");
        return;
    }
    if(front==rear)
        front=rear=-1;
    else
        front++;
}

void insert_middle(ll num)
{
    if(rear==siz-1){
        printf("\nQueue full\n");
        return;
    }
    if(front==-1)
        queue[++front]=num,rear++;
    else{
        ll mid=(rear+front)/2;
        ll pos=rear++;
        while(pos>mid)
        {
            queue[pos+1]=queue[pos];
            pos--;
        }
        queue[pos+1]=num;
    }
}

void delete_middle()
{
    if(front==-1)
    {
        printf("\nQueue Empty\n");
        return;
    }
    ll mid=(front+rear+1)/2;
    while(mid>front)
    {
        queue[mid]=queue[mid-1];
        mid--;
    }
    if(front==rear)
        front=rear=-1;
    else
        front++;
}

void show()
{
    if(front==-1)
    {
        printf("\nQueue Empty\n");
        return;
    }
    else
    {
        for(ll i=front;i<=rear;i++)
            printf("%lld ",queue[i] );
    }

}

int main(){
    front=rear=-1;

    while(1)
    {
        printf("Choose Your option\n");
        printf("1: Input at middle\n");
        printf("2: Delete at middle\n");
        printf("3: Exit\n");
        ll op;
        scanf("%lld",&op);
        if(op==3)
            exit(0);
        if(op==1)
        {
            ll x;
            scanf("%lld",&x);
            insert_middle(x);
            printf("\nAfter Insertion Queue is :\n");
            show();
            printf("\n");
        }
        else if(op==2){
            delete_middle();
            printf("\nAfter Deletion Queue is :\n");
            show();
            printf("\n");
        }
        else
        {
            printf("\nInvalid Input\n");
        }

    }
    return 0;
}