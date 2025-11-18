#include <stdio.h>

int main() {
    int a[100], n, top = -1, ch, v, i;
    printf("Enter stack size: ");
    scanf("%d", &n);
    while (1) {
        printf("\n1 Push\n2 Pop\n3 Peek\n4 Display\n5 Is Empty\n6 Is Full\n7 Size\n8 Exit\nChoose: ");
        scanf("%d", &ch);
        if (ch == 1) {
            if (top == n - 1) printf("Stack Full\n");
            else {
                printf("Enter value: ");
                scanf("%d", &v);
                top++;
                a[top] = v;
                printf("Pushed %d\n", v);
            }
        } else if (ch == 2) {
            if (top == -1) printf("Stack Empty\n");
            else {
                printf("Popped %d\n", a[top]);
                top--;
            }
        } else if (ch == 3) {
            if (top == -1) printf("Stack Empty\n");
            else printf("Top: %d\n", a[top]);
        } else if (ch == 4) {
            if (top == -1) printf("Stack Empty\n");
            else {
                printf("Stack: ");
                for (i = top; i >= 0; i--) printf("%d ", a[i]);
                printf("\n");
            }
        } else if (ch == 5) {
            if (top == -1) printf("Yes, stack is empty\n");
            else printf("No, stack is not empty\n");
        } else if (ch == 6) {
            if (top == n - 1) printf("Yes, stack is full\n");
            else printf("No, stack is not full\n");
        } else if (ch == 7) {
            printf("Current size: %d\n", top + 1);
        } else if (ch == 8) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}