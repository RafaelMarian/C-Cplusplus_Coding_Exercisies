#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL,*third=NULL;

void create(int A[], int n){
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p){
    while(p!=NULL){
        printf("%d",p->data);
        p=p->next;
    }
}
void DisplayRecursive(struct Node *p){
    while(p!=NULL){
        printf("%d",p->data);
        DisplayRecursive(p->next);
    }
} 

int count(struct Node *p){
    int count=0;
    while(p!=NULL){
        count++;
        p=p->next;
    }
    printf("%d", count);
}
int add(struct Node *p){
    int sum= 0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    printf("%d",sum);
}
int max(struct Node *p){
    int m=-32768;
    while(p){
        if(p->data>m)
        {
            m=p->data;
            p=p->next;
        }
    }
    return m;
}
struct Node *LinearSearche(struct Node *p, int key){
  struct Node *q;
    while(p!=NULL)
    {
    if(key==p->data)
    {
        q->next=p->next;
        p->next=first;
        first=p;
        return p;
    }
        q=p;
        p=p->next;
    }
    return NULL;

}
struct Node * RSearch(struct Node *p, int key){
    if(p==NULL)
        return NULL;
    if(key==p->data)
        return p;
    return RSearch(p->next, key);
}
void Inserting(struct Node *p, int x, int index){
    struct Node *t;
    int i;
    if(index<=0 || index>= count(p)){
        return ;
    }else{
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
    }

    if(index==0){
    t->next=first;
    first=t;
    }else{
        for(i=0;i<index;i++){
            p=p->next;
            t->next=p->next;
            p->next=t;
        }
    }
  

}
void InsertLast(int x)
{
    struct Node *t,*last;
    int i;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if(first==NULL){
        first=last=t;
    }else{
        last->next=t;
        last=t;
    }
}
int DeleteFirstNode(struct Node *p){
    struct Node *t;
    int x = -1;
    t=first;
    first=first->next;
    x=t->data;
    free(t);
    return x;
}
int DeleteAnyNode(struct Node *a, int index){
    struct Node *p=first;
    struct Node *q=NULL;
    int x = -1;
    for(int i=0;i<index;i++){
        q=p;
        p=p->next;
    }
    q->next=p->next;
    x=p->data;
    free(p);
    return x;

}
int isSorted(struct Node *p){
    int x=-65536;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }else{
            x=p->data;
            p=p->next;
        }
    }

}
void RemoveDuplicate(struct Node *p){
    struct Node *q = p->next;
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}
void Reverse(struct Node *p){
    struct Node *r=NULL;
    struct Node *q=NULL;
    p=first;
    while(p!=NULL){
        r=q;
        r=p;
        p=p->next;
        q->next=r;
    }

}
void Merge(struct Node *p, struct Node *q){
    struct Node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }while(p && q){
        if(p->data <q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)last->next=p;
    if(q)last->next=q;
}
int isLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && q && p!=q);
        if(p==q)
         return 1;
        else
         return 0;
}
int main(){
    int choice, x, index, key;
    struct Node *temp;

    int A[]={3,5,7,10,15};
    create(A,5);

    do {
        printf("\nMenu:\n");
        printf("1. Display\n");
        printf("2. Display Recursive\n");
        printf("3. Count Nodes\n");
        printf("4. Sum of Nodes\n");
        printf("5. Maximum Node\n");
        printf("6. Linear Search\n");
        printf("7. Recursive Search\n");
        printf("8. Insert Node\n");
        printf("9. Insert Last\n");
        printf("10. Delete First Node\n");
        printf("11. Delete Node at Index\n");
        printf("12. Check if Sorted\n");
        printf("13. Remove Duplicates\n");
        printf("14. Reverse List\n");
        printf("15. Merge Lists\n");
        printf("16. Check for Loop\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 0:
                printf("Exiting program.\n");
                break;
            case 1:
                Display(first);
                break;
            case 2:
                DisplayRecursive(first);
                break;
            case 3:
                printf("Number of nodes: %d\n", count(first));
                break;
            case 4:
                printf("Sum of nodes: %d\n", add(first));
                break;
            case 5:
                printf("Maximum node: %d\n", max(first));
                break;
            case 6:
                printf("Enter key for linear search: ");
                scanf("%d", &key);
                temp = LinearSearche(first, key);
                if (temp)
                    printf("Key %d found at node with data %d\n", key, temp->data);
                else
                    printf("Key %d not found\n", key);
                break;
            case 7:
                printf("Enter key for recursive search: ");
                scanf("%d", &key);
                temp = RSearch(first, key);
                if (temp)
                    printf("Key %d found at node with data %d\n", key, temp->data);
                else
                    printf("Key %d not found\n", key);
                break;
            case 8:
                printf("Enter data for new node: ");
                scanf("%d", &x);
                printf("Enter index for insertion: ");
                scanf("%d", &index);
                Inserting(first, x, index);
                break;
            case 9:
                printf("Enter data for new node: ");
                scanf("%d", &x);
                InsertLast(x);
                break;
            case 10:
                printf("Deleted node data: %d\n", DeleteFirstNode(first));
                break;
            case 11:
                printf("Enter index for deletion: ");
                scanf("%d", &index);
                printf("Deleted node data: %d\n", DeleteAnyNode(first, index));
                break;
            case 12:
                if (isSorted(first))
                    printf("The list is sorted.\n");
                else
                    printf("The list is not sorted.\n");
                break;
            case 13:
                RemoveDuplicate(first);
                break;
            case 14:
                Reverse(first);
                break;
            case 15:
                break;
            case 16:
                if (isLoop(first))
                    printf("The list contains a loop.\n");
                else
                    printf("The list does not contain a loop.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while(choice != 0);

    return 0;
}