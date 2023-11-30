#include<stdio.h>
#include<stdlib.h>
#include "QueueHeaderFile.h"
struct Node *root=NULL;
void Treecreate(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    printf("Enter root value: ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    while(!isEmpty(q)){
        p=dequeue(&q);
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("eneter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1){
            t=(struct Node *)malloc(sizeof(struct
            Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}
void Preorder(struct Node *p){
    if(p)
    {
    printf("%d ",p->data);
    Preorder(p->lchild);
    Preorder(p->rchild);
    }
}
void Inorder(struct Node *p){
    if(p)
    {
    Inorder(p->lchild);
    printf("%d ",p->data);
    Inorder(p->rchild);
    }
}
void Postorder(struct Node *p){
    if(p)
    {
    Postorder(p->lchild);
    Postorder(p->rchild);
    printf("%d ",p->data);
    }
}
int count(struct Node *root){
    if(root)
    return count(root->lchild)+count(root->rchild)+1;
    return 0;
}
int height(struct Node *root){
    int x=0,y=0;
    if(root==0)
    return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
    return x+1;
    else
    return y+1;
}
void Levelorder(struct Node *p){
    struct Queue q;
    create(&q,100);
    printf("%d",p->data);
    enqueue(&q,p);
    while(!isEmpty(q)){
        p=dequeue(&q);
        if(p->lchild){
            printf("%d",p->lchild->data);
            enqueue(&q,p->lchild);
        };
          if(p->rchild){
            printf("%d",p->rchild->data);
            enqueue(&q,p->rchild);
        };

    }
}
int main() {
    int choice;

    do {
        printf("\n------ Binary Tree Menu ------\n");
        printf("1. Create Tree\n");
        printf("2. Preorder Traversal\n");
        printf("3. Inorder Traversal\n");
        printf("4. Postorder Traversal\n");
        printf("5. Count Nodes\n");
        printf("6. Tree Height\n");
        printf("7. Level Order Traversal\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Treecreate();
                break;
            case 2:
                printf("Preorder Traversal: ");
                Preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder Traversal: ");
                Inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder Traversal: ");
                Postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Number of Nodes: %d\n", count(root));
                break;
            case 6:
                printf("Tree Height: %d\n", height(root));
                break;
            case 7:
                printf("Level Order Traversal: ");
                Levelorder(root);
                printf("\n");
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