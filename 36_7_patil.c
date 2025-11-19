#include <stdio.h>
#include <string.h>
#include <ctype.h>

int prec(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/' || c == '%') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char s[200], stack[200], post[200];
    int ch;

    while (1) {
        printf("\n1 Convert Infix to Postfix\n2 Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter infix expression: ");
            scanf("%s", s);

            int top = -1, j = 0, i;

            for (i = 0; i < strlen(s); i++) {
                if (isalnum(s[i])) {
                    post[j++] = s[i];
                }
                else if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    top++;
                    stack[top] = s[i];
                }
                else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    char o = (s[i] == ')') ? '(' : (s[i] == '}') ? '{' : '[';
                    while (top != -1 && stack[top] != o) {
                        post[j++] = stack[top];
                        top--;
                    }
                    if (top != -1) top--;
                }
                else {
                    while (top != -1 && prec(stack[top]) >= prec(s[i])) {
                        if (stack[top] == '(' || stack[top] == '{' || stack[top] == '[') break;
                        post[j++] = stack[top];
                        top--;
                    }
                    top++;
                    stack[top] = s[i];
                }
            }

            while (top != -1) {
                post[j++] = stack[top];
                top--;
            }

            post[j] = '\0';

            printf("Postfix: %s\n", post);
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