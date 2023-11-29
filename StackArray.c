
#include <stdlib.h>
#include <stdio.h>

struct Stack{
    int size;
    int top;
    int *s;
};
void create(struct Stack *st){
    printf("Enter the size of the stack: ");
    scanf("%d",&st->size);
    st->s=(int *)malloc(sizeof(int));
    st->top=-1;
}
void Display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i++){
        printf("%d",st.s[i]);
        
    }
}
void push(struct Stack *st, int x){
    if(st->top==st->size-1){
        printf("Stack Overflow");

    }else{
        st->top++;
        st->s[st->top]=x;
    }
}
int pop(struct Stack *st){
    int x=-1;
    if(st->top==-1){
        printf("to low");

    }else{
        x=st->s[st->top];
        st->top--;
    }
    return x;
}
int peek(struct Stack st,int index){
    int x=-1;
    if(st.top-index+1<0){
        printf("Invalid Index\n");
    }else{
        x=st.s[st.top-index+1];
    }
    return x;
}
int isEmpty(struct Stack st)
{
    if(st.top==-1)
    return 1;
    return 0;
}
int isFull(struct Stack st)
{
    return st.top==st.size-1;
}
int stackTop(struct Stack st)
{
    if(!isEmpty(st))
    return st.s[st.top];
    return -1;
}
int main() {
    struct Stack st;
    create(&st);

    int choice, value;

    do {
        printf("\n------ Stack Menu ------\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Stack Top\n");
        printf("6. Is Empty\n");
        printf("7. Is Full\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&st, value);
                break;
            case 2:
                pop(&st);
                break;
            case 3:
                printf("Enter index to peek: ");
                scanf("%d", &value);
                printf("Element at index %d is: %d\n", value, peek(st, value));
                break;
            case 4:
                Display(st);
                break;
            case 5:
                printf("Stack Top: %d\n", stackTop(st));
                break;
            case 6:
                printf(isEmpty(st) ? "Stack is empty\n" : "Stack is not empty\n");
                break;
            case 7:
                printf(isFull(st) ? "Stack is full\n" : "Stack is not full\n");
                break;
            case 8:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 8);

    return 0;
}