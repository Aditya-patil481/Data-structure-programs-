#include <stdio.h>

int main() {
    int n, stack[100], top, ch, i;

    while (1) {
        printf("\n1 Convert Decimal to Binary\n2 Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter decimal number: ");
            scanf("%d", &n);

            if (n == 0) {
                printf("Binary: 0\n");
                continue;
            }

            top = -1;
            int x = n;

            while (x > 0) {
                top++;
                stack[top] = x % 2;
                x = x / 2;
            }

            printf("Binary: ");
            for (i = top; i >= 0; i--) printf("%d", stack[i]);
            printf("\n");
        }

        else if (ch == 2) {
            break;
        }

        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}