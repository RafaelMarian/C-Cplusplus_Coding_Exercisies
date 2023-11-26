#include<stdint.h>
#include<stdio.h>

int lenght(char *a){
    int i;
    for(i=0;a[i] != '\0';i++){
    }
    printf("The length of the string is: %d",i);
}

void UpperCase(char *a){
    int i;
    for(i=0;a[i] !='\0';i++){
        a[i]-=32;
    }
    printf("%s",a);
}
void Reversing(char *a){
    char b[28];
    int i,j;
    int length = 0;
    while (a[length] != '\0') {
        length++;
    }
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        b[j] = a[i];
    }
    b[j] = '\0';
    printf("Reversed string: %s\n", b);
}
void Comparing(char *a, char *b){
    int i, j;
    for(i=0, j=0; a[i]!='\0' && b[j]!='\0';i++,j++){
        if(a[i]!=b[j]){
            printf("\nNot equal\n");
            break;
        }else if(a[i]==b[j]){
            printf("Equal");
        }else if(a[i]>b[j]){
            printf("Grater 1");
        }else{
            printf("Grater 2");
        }
    }

}
int isPalindrome(char *a) {
    int length=0;
    while (a[length] != '\0') {
        length++;
    }    for (int i = 0, j = length - 1; i < j; i++, j--) {
        if (a[i] != a[j]) {
            printf("Not palindrom");
            return 0;
        }
    }
    printf("Palindrom");
    return 1;  
}
void Duplicates(char *a){
    int H[26]={0};
    int i;
    for(i=0;a[i] !='\0';i++){
        H[a[i]-97]+=1;
    }
    printf("Duplicate characters: ");
    for(i=0;i<26;i++){
        if(H[i]>1){
            printf("%c",i+97);
        }
    }
}
void Anagram(char *a, char *b){
    int H[50]={0};
    int i;
     for(i=0;a[i] !='\0';i++){
        H[a[i]-97]+=1;
    }
     for(i=0;b[i] !='\0';i++){
        H[b[i]-97]-=1;
    }

     for (i = 0; i < 26; i++) {
        if (H[i] != 0) {
            printf("Not an anagram\n");
            return;
        }
    }

    printf("Anagram\n");
}
int arePermutations(char *a, char *b) {
    int count[256] = {0};
    for (int i = 0; a[i] != '\0'; i++) {
        count[a[i]]++;
    }

    for (int i = 0; b[i] != '\0'; i++) {
        count[b[i]]--;
    }
    for (int i = 0; i < 256; i++) {
        if (count[i] != 0) {
            return 0;  
        }
    }

    return 1; 
}
int main() {
    char s1[] = "wellcome";
    char s2[] = "home";

    int choice;
    printf("Menu:\n");
    printf("1. Reversing\n");
    printf("2. Length\n");
    printf("3. Uppercase\n");
    printf("4. Comparing\n");
    printf("5. Palindrome Check\n");
    printf("6. Duplicates\n");
    printf("7. Anagram Check\n");
    printf("8. Permutation Check\n");
    printf("Enter your choice (1-8): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            Reversing(s1);
            break;
        case 2:
            lenght(s1);
            break;
        case 3:
            UpperCase(s1);
            break;
        case 4:
            Comparing(s1, s2);
            break;
        case 5:
            isPalindrome(s1);
            break;
        case 6:
            Duplicates(s1);
            break;
        case 7:
            Anagram(s1, s2);
            break;
        case 8:
            if (arePermutations(s1, s2)) {
                printf("The strings are permutations.\n");
            } else {
                printf("The strings are not permutations.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}