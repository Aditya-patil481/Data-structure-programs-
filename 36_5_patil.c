#include <stdio.h>
#include <string.h>

int main() {
    char s[200];
    int ch;

    while (1) {
        printf("\n1 Check Parenthesis\n2 Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter expression: ");
            scanf("%s", s);

            int stack[200], top = -1;
            int ok = 1, i;

            for (i = 0; i < strlen(s); i++) {
                if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                    top++;
                    stack[top] = s[i];
                } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                    if (top == -1) {
                        ok = 0;
                        break;
                    }
                    char t = stack[top];
                    if ((s[i] == ')' && t != '(') ||
                        (s[i] == '}' && t != '{') ||
                        (s[i] == ']' && t != '[')) {
                        ok = 0;
                        break;
                    }
                    top--;
                }
            }

            if (top != -1) ok = 0;

            if (ok) printf("Balanced\n");
            else printf("Not Balanced\n");
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