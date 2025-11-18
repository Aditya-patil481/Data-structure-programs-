#include <stdio.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int a[n], top1 = -1, top2 = n, ch, v, i;

    while (1) {
        printf("\n1 Push Stack1\n2 Push Stack2\n3 Pop Stack1\n4 Pop Stack2\n5 Display\n6 Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) {
            if (top1 + 1 == top2) printf("Overflow\n");
            else {
                printf("Enter value: ");
                scanf("%d", &v);
                top1++;
                a[top1] = v;
                printf("Pushed %d in Stack1\n", v);
            }
        }

        else if (ch == 2) {
            if (top2 - 1 == top1) printf("Overflow\n");
            else {
                printf("Enter value: ");
                scanf("%d", &v);
                top2--;
                a[top2] = v;
                printf("Pushed %d in Stack2\n", v);
            }
        }

        else if (ch == 3) {
            if (top1 == -1) printf("Underflow Stack1\n");
            else {
                printf("Popped %d from Stack1\n", a[top1]);
                top1--;
            }
        }

        else if (ch == 4) {
            if (top2 == n) printf("Underflow Stack2\n");
            else {
                printf("Popped %d from Stack2\n", a[top2]);
                top2++;
            }
        }

        else if (ch == 5) {
            printf("Stack1: ");
            if (top1 == -1) printf("Empty");
            else for (i = top1; i >= 0; i--) printf("%d ", a[i]);

            printf("\nStack2: ");
            if (top2 == n) printf("Empty");
            else for (i = top2; i < n; i++) printf("%d ", a[i]);

            printf("\n");
        }

        else if (ch == 6) break;
        else printf("Invalid choice\n");
    }

    return 0;
}