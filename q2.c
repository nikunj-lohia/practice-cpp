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
//display stack
int stack_display(struct Queue * q) {
    int i = (q->rear) % q->capacity, n = q->count;
    int count=0;
    while (n--) {
        printf("%d ", q->arr[i]);
        i =(i-1)%q->capacity;
        count++;
    }
    if(count==0)
    {
        printf("Stack Is Empty\n");
    }
    return count;
}


#define capacity 10000
int main(void) {

    struct Queue *q= createQueue(capacity);//max capacity-->100
    int x, select;
    printf("Choose your option\n");
    printf("1) Push\n2) Pop\n3) Exit");
    select=-1;
    while(1){
        printf("\n\nChoice: ");
        scanf(" %d", &select);
        if(select==3){
            break;
        }
        else if(select==1){
            printf("Enter value to Push in stack:");
            scanf(" %d", &x);
            stack_push(q, x);
            printf("\nThe current stack is:\n");
            stack_display(q);
            printf("\nPushed Value: %d", x);
        }
        else if(select==2){
            x = stack_pop(q);
            if(x==0)continue;
            stack_display(q);
            printf("\nThe current stack is:\n");
            stack_display(q);
            printf("\nPushed Value: %d", x);

        }
        else{
            printf("Wrong option!!");
        }
    }
    return 0;
}