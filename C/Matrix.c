#include <stdio.h>
#include <stdlib.h>
struct Matrix{
    int *A;
    int n;
};
void SetDiagonalMatrix(struct Matrix *m, int i, int j, int x){
    if(i==j){
        m->A[i-1]=x;
    }
}
int GetDiagonalMatrix(struct Matrix *m, int i, int j){
    if(i==j){
        return m->A[i-1];
    }else{
        return 0;
    }
}
void SetLowerTriangleMatrix(struct Matrix *m, int i, int j, int x){
    if(i>=j){
        m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x;
    }
}
int GetLowerTriangleMatrix(struct Matrix *m, int i, int j){
    if(i>=j){
        return m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j];
    }else{
        return 0;
    }
}
void DisplayDiagonalMatrix(struct Matrix *m){
   int i,j;
    for(i=0;i<m->n;i++){
        for(j=0;j<m->n;j++){
            if(i==j){
                printf("%d ",m->A[i]);
            }else{
                printf("0 ");
            }
        }
                printf("\n");

    }
}
void DisplayLowerTriangleMatrix(struct Matrix *m){
    int i,j;
    for(i=0;i<=m->n;i++){
        for(j=0;j<=m->n;j++){
            if(i>=j){
                printf("%d ",m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]);
            }else{
                printf("0 ");
            }
        }
                printf("\n");
    }
}

void SetUpperTriangleMatrix(struct Matrix *m, int i, int j, int x) {
    if (i <= j) {
        m->A[m->n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - i] = x;
    }
}

int GetUpperTriangleMatrix(struct Matrix *m, int i, int j) {
    if (i <= j) {
        return m->A[m->n * (i - 1) - ((i - 2) * (i - 1)) / 2 + j - i];
    } else {
        return 0;
    }
}

void DisplayUpperTriangleMatrix(struct Matrix *m) {
    int i, j;
    for (i = 1; i <= m->n; i++) {
        for (j = 1; j <= m->n; j++) {
            if (i <= j) {
                printf("%d ", GetUpperTriangleMatrix(m, i, j));
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main(){
   struct Matrix m;
    int i, j, x, choice;

    printf("Enter Dimension: ");
    scanf("%d", &m.n);

    m.A = (int *)malloc(m.n * (m.n + 1) / 2 * sizeof(int));

    printf("Choose matrix type:\n");
    printf("1. Diagonal Matrix\n");
    printf("2. Lower Triangle Matrix\n");
    printf("3. Upper Triangle Matrix\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter diagonal elements:\n");
            for (i = 1; i <= m.n; i++) {
                scanf("%d", &x);
                SetDiagonalMatrix(&m, i, i, x);
            }
            printf("Diagonal Matrix:\n");
            DisplayDiagonalMatrix(&m);
            break;

        case 2:
            printf("Enter lower triangle elements:\n");
            for (i = 1; i <= m.n; i++) {
                for (j = 1; j <= m.n; j++) {
                    scanf("%d", &x);
                    SetLowerTriangleMatrix(&m, i, j, x);
                }
            }
            printf("Lower Triangle Matrix:\n");
            DisplayLowerTriangleMatrix(&m);
            break;

        case 3:
            printf("Enter upper triangle elements:\n");
            for (i = 1; i <= m.n; i++) {
                for (j = 1; j <= m.n; j++) {
                    scanf("%d", &x);
                    SetUpperTriangleMatrix(&m, i, j, x);
                }
            }
            printf("Upper Triangle Matrix:\n");
            DisplayUpperTriangleMatrix(&m);
            break;

        default:
            printf("Invalid choice\n");
            break;
                }

    free(m.A);

    return 0;
}