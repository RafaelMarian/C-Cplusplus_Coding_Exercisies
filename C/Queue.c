#include <stdlib.h>
#include <stdio.h>
struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size){
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(int *)malloc(sizeof(int)*q->size);
}
void enqueue(struct Queue *q, int x){
    if(q->rear==q->size-1){
        printf("Queue is full");
    }else{
        q->rear++;
        q->Q[q->rear]=x;
    }
}
int dequeue(struct Queue *q){
    int x=-1;
    if(q->front==q->rear)
    printf("Queue is Empty\n");
    else
    {
    q->front++;
    x=q->Q[q->front];
    }
    return x;
}
void Display(struct Queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++){
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
int main() {
    struct Queue q;
    create(&q, 5);

    int choice, value;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("Dequeued element: %d\n", value);
                }
                break;

            case 3:
                Display(q);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}