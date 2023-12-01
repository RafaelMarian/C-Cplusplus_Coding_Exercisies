#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *A;
    int size;
    int length;
};

void Display(struct Array a) {
    printf("\nElements are\n");
    for (int i = 0; i < a.length; i++) {
        printf("%d ", a.A[i]);
    }
    printf("\n");
}

void Append(struct Array *a, int x) {
    if (a->length < a->size) {
        a->A[a->length++] = x;
    }
}

void Insert(struct Array *a, int index, int x) {
    if (index >= 0 && index <= a->length) {
        for (int i = a->length - 1; i >= index; i--) {
            a->A[i + 1] = a->A[i];
        }
        a->A[index] = x;
        a->length++;
    }
}

int Delete(struct Array *a, int index) {
    int x = 0;
    if (index >= 0 && index < a->length) {
        x = a->A[index];
        for (int i = index; i < a->length - 1; i++) {
            a->A[i] = a->A[i + 1];
        }
        a->length--;
    }
    return x;
}

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Get(struct Array *a, int index) {
    if (index >= 0 && index < a->length) {
        return a->A[index];
    }
    return -1;
}

int Set(struct Array *a, int index, int x) {
    if (index >= 0 && index < a->length) {
        a->A[index] = x;
        return 0;
    }
    return -1;
}

int Max(struct Array *a) {
    int max = a->A[0];
    for (int i = 1; i < a->length; i++) {
        if (a->A[i] > max) {
            max = a->A[i];
        }
    }
    return max;
}

int Min(struct Array *a) {
    int min = a->A[0];
    for (int i = 1; i < a->length; i++) {
        if (a->A[i] < min) {
            min = a->A[i];
        }
    }
    return min;
}

int Sum(struct Array *a) {
    int sum = 0;
    for (int i = 0; i < a->length; i++) {
        sum += a->A[i];
    }
    return sum;
}

float Avg(struct Array a) {
    return (float)Sum(&a) / a.length;
}

void Reverse2(struct Array *a) {
    for (int i = 0, j = a->length - 1; i < j; i++, j--) {
        swap(&a->A[i], &a->A[j]);
    }
}

int LinearSearch(struct Array *a, int key) {
    int i;
    for (i = 0; i < a->length; i++) {
        if (key == a->A[i]) {
            swap(&a->A[i], &a->A[0]);
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array *a, int l, int h, int key) {
    while (l <= h) {
        int mid = (l + h) / 2;
        if (key == a->A[mid]) {
            return mid;
        } else if (key < a->A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int isSorted(struct Array a) {
    for (int i = 0; i < a.length - 1; i++) {
        if (a.A[i] > a.A[i + 1]) {
            return 0;
        }
    }
    return 1;
}

struct Array *Merge(struct Array *arr1, struct Array *arr2) {
    int i, j, k;
    i = j = k = 0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    arr3->size = arr1->size + arr2->size;
    arr3->A = (int *)malloc(arr3->size * sizeof(int));

    while (i < arr1->length && j < arr2->length) {
        if (arr1->A[i] < arr2->A[j]) {
            arr3->A[k++] = arr1->A[i++];
        } else {
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for (; i < arr1->length; i++) {
        arr3->A[k++] = arr1->A[i];
    }
    for (; j < arr2->length; j++) {
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = k;
    return arr3;
}

void InsertSort(struct Array *a, int x) {
    int i = a->length - 1;
    if (a->length == a->size) {
        return;
    }
    while (i >= 0 && a->A[i] > x) {
        a->A[i + 1] = a->A[i];
        i--;
    }
    a->A[i + 1] = x;
    a->length++;
}

int main() {
    struct Array arr1;
    int ch;
    int x, index;

    printf("Enter Size of Array: ");
    scanf("%d", &arr1.size);
    arr1.A = (int *)malloc(arr1.size * sizeof(int));
    arr1.length = 0;

    do {
        printf("\n\nMenu\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Sum\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter an element and index: ");
                scanf("%d%d", &x, &index);
                Insert(&arr1, index, x);
                break;

            case 2:
                printf("Enter index: ");
                scanf("%d", &index);
                x = Delete(&arr1, index);
                printf("Deleted Element is %d\n", x);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &x);
                index = LinearSearch(&arr1, x);
                printf("Element index %d\n", index);
                break;

            
            case 4:
                printf("Sum is %d\n", Sum(&arr1));
                break;

            case 5:
                Display(arr1);
                break;
        }
    } while (ch < 6);

    // Free allocated memory
    free(arr1.A);

    return 0;
}