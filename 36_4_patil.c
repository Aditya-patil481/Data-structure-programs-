#include <stdio.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);

    int a[n];
    int mid = n / 2;

    int f1 = 0, r1 = -1;
    int f2 = mid, r2 = mid - 1;

    int ch, v, i;

    while (1) {
        printf("\n1 Enqueue Q1\n2 Enqueue Q2\n3 Dequeue Q1\n4 Dequeue Q2\n5 Display\n6 Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) {
            if (r1 + 1 == mid) printf("Overflow Q1\n");
            else {
                printf("Enter value: ");
                scanf("%d", &v);
                r1++;
                a[r1] = v;
                printf("Enqueued %d in Q1\n", v);
            }
        }

        else if (ch == 2) {
            if (r2 + 1 == n) printf("Overflow Q2\n");
            else {
                printf("Enter value: ");
                scanf("%d", &v);
                r2++;
                a[r2] = v;
                printf("Enqueued %d in Q2\n", v);
            }
        }

        else if (ch == 3) {
            if (f1 > r1) printf("Underflow Q1\n");
            else {
                printf("Dequeued %d from Q1\n", a[f1]);
                f1++;
            }
        }

        else if (ch == 4) {
            if (f2 > r2) printf("Underflow Q2\n");
            else {
                printf("Dequeued %d from Q2\n", a[f2]);
                f2++;
            }
        }

        else if (ch == 5) {
            printf("Q1: ");
            if (f1 > r1) printf("Empty");
            else for (i = f1; i <= r1; i++) printf("%d ", a[i]);

            printf("\nQ2: ");
            if (f2 > r2) printf("Empty");
            else for (i = f2; i <= r2; i++) printf("%d ", a[i]);

            printf("\n");
        }

        else if (ch == 6) break;
        else printf("Invalid choice\n");
    }

    return 0;
}