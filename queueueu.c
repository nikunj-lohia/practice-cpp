#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int *arr;
    int rear;
    int front;
    int count;
    int capacity;
};


struct Queue *createQueue(int n) {
    struct Queue *queue;

    queue = malloc(sizeof(struct Queue));
    if (queue == NULL)
        return NULL;
    queue->capacity = n;
    queue->count=0;
    queue->arr = (int*)malloc(sizeof(int) * n);
    queue->rear = n - 1;
    queue->front = n - 1;

    return queue;
}
void print_que(struct Queue *q)
{
    int k=q->count;
    while(k--)
    {
         q->front=(q->front+1)% q->capacity;
        printf("%d ",q->arr[q->front]);  
    }
}

void enQueue(struct Queue * q, int val) {
    if (q->count == q->capacity){
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->arr[q->rear] = val;
    q->count++;
}

int deQueue(struct Queue * q) {
    int val;
    if (q->count == 0)
    {
        printf("Sorry! Nothing to remove \n");
        return 0;
    }
    q->front = (q->front + 1) % q->capacity;
    val = q->arr[q->front];
    q->count--;

    return val;
}

int queue_is_empty(struct Queue * q) {
    return (q->count == 0);
}
#define capacity 10000
int main(void) {

    struct Queue *q1= createQueue(capacity);//max capacity-->100
    struct Queue *q2= createQueue(capacity);//max capacity-->100
    int x;
    scanf("%d",&x);
    for(int i=0;i<x;i++)
    {
        int p;
        scanf("%d",&p);
        enQueue(q1,p);
    }
    
    int k;
    scanf("%d",&k);
    int a[k];
    for(int i=0;i<k;i++)
    {
        a[i]=deQueue(q1);
    }
    for(int i=k-1;i>=0;i--)
    {
        enQueue(q2,a[i]);
    }
    while(!queue_is_empty(q1))
    {
        enQueue(q2,deQueue(q1));
    }
    print_que(q2);
}