#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

void reverse(char s[]) {
    int i, j;
    char t;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int main() {
    char inf[200], rev[200], post[200], pre[200];
    char st[200];
    int ch;

    while (1) {
        printf("\n1 Infix to Prefix\n2 Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter infix expression: ");
            scanf("%s", inf);

            strcpy(rev, inf);
            reverse(rev);

            int i;
            for (i = 0; i < strlen(rev); i++) {
                if (rev[i] == '(') rev[i] = ')';
                else if (rev[i] == ')') rev[i] = '(';
            }

            int top = -1, j = 0;
            for (i = 0; i < strlen(rev); i++) {
                if (isalnum(rev[i])) {
                    post[j++] = rev[i];
                }
                else if (rev[i] == '(') {
                    top++;
                    st[top] = rev[i];
                }
                else if (rev[i] == ')') {
                    while (top != -1 && st[top] != '(') {
                        post[j++] = st[top];
                        top--;
                    }
                    if (top != -1) top--;
                }
                else {
                    while (top != -1 && prec(st[top]) >= prec(rev[i])) {
                        if (st[top] == '(') break;
                        post[j++] = st[top];
                        top--;
                    }
                    top++;
                    st[top] = rev[i];
                }
            }

            while (top != -1) {
                post[j++] = st[top];
                top--;
            }
            post[j] = '\0';

            strcpy(pre, post);
            reverse(pre);

            printf("Prefix: %s\n", pre);
        }

        else if (ch == 2) break;
        else printf("Invalid choice\n");
    }

    return 0;
}