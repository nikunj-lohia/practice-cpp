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

void stack_push(struct Queue * q, int v) {
    enQueue(q, v);
}

int stack_pop(struct Queue * q) {
    int i, n = q->count;
    int removed_element;

    for (i = 0; i < (n - 1); i++) {
        removed_element = deQueue(q);
        enQueue(q, removed_element);
    }
    removed_element = deQueue(q);

    return removed_element;
}
int stack_top(struct Queue * q)
{
    int i=(q->rear) % q->capacity;
    int k=q->arr[i];
    return k;

}
int stack_display(struct Queue * q) {
    int i = (q->rear) % q->capacity, n = q->count;
    int count=0;
    while (n--) {
       // printf("%d ", q->arr[i]);
        i =(i-1)%q->capacity;
        count++;
    }
    if(count==0)
    {
        return 1;
    }
    return 0;
}


#define capacity 10000
int main(void) {
 
    char s[1000];
    struct Queue *q1= createQueue(10000);
    scanf("%s",s);
    int i=0;
    while(s[i]!='\0')
    {
      if(s[i]=='(')
        stack_push(q1,'(');
      else if(s[i]==')')
        {
            if(stack_top(q1)=='(')
              {
                  int k=stack_pop(q1);
              }
              else
              stack_push(q1,')');
        }
        i++;
    }
    if(stack_display(q1)==1)
    printf("balanced");
    else
    printf("unbalalnced");
    return 0;
}