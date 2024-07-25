#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void create();
void insert();
void deletion();
void search();
void display();

int b[MAX], n = 0;

int main() {
    int ch;
    char g = 'y';
    do {
        printf("\nMain Menu");
        printf("\n1. Create \n2. Delete \n3. Search \n4. Insert \n5. Display \n6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create();
                break;
            case 2:
                deletion();
                break;
            case 3:
                search();
                break;
            case 4:
                insert();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("\nEnter the correct choice:");
        }
        printf("\nDo you want to continue (y/n): ");
        scanf(" %c", &g); // Notice the space before %c to consume any leftover newline character
    } while (g == 'y' || g == 'Y');

    return 0;
}

void create() {
    printf("\nEnter the number of elements: ");
    scanf("%d", &n);
    if (n > MAX) {
        printf("\nCannot create list with more than %d elements.\n", MAX);
        n = 0;
        return;
    }
    printf("\nEnter the elements:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &b[i]);
    }
}

void deletion() {
    int pos;
    if (n == 0) {
        printf("\nThe list is empty.\n");
        return;
    }
    printf("\nEnter the position you want to delete: ");
    scanf("%d", &pos);
    if (pos >= n || pos < 0) {
        printf("\nInvalid Location.\n");
        return;
    }
    for (int i = pos; i < n - 1; i++) {
        b[i] = b[i + 1];
    }
    n--;
    printf("\nThe elements after deletion are:\n");
    display();
}

void search() {
    int e, found = 0;
    printf("\nEnter the element to be searched: ");
    scanf("%d", &e);
    for (int i = 0; i < n; i++) {
        if (b[i] == e) {
            printf("\nValue %d is in position %d.\n", e, i);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nValue %d is not in the list.\n", e);
    }
}

void insert() {
    int pos, p;
    if (n >= MAX) {
        printf("\nThe list is full.\n");
        return;
    }
    printf("\nEnter the position you need to insert: ");
    scanf("%d", &pos);
    if (pos > n || pos < 0) {
        printf("\nInvalid Location.\n");
        return;
    }
    for (int i = n; i > pos; i--) {
        b[i] = b[i - 1];
    }
    printf("\nEnter the element to insert: ");
    scanf("%d", &p);
    b[pos] = p;
    n++;
    printf("\nThe list after insertion is:\n");
    display();
}

void display() {
    printf("\nThe elements of the list ADT are:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
   printf("\n");
}