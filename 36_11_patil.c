#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int prec(char c) {
    if (c=='+'||c=='-') return 1;
    if (c=='*'||c=='/') return 2;
    if (c=='^') return 3;
    return 0;
}

int apply(int a, int b, char op) {
    if (op=='+') return a+b;
    if (op=='-') return a-b;
    if (op=='*') return a*b;
    if (op=='/') return a/b;
    if (op=='^') {
        int r=1;
        for(int i=0;i<b;i++) r*=a;
        return r;
    }
    return 0;
}

int main() {
    char exp[200];
    int values[200], topv=-1;
    char ops[200];
    int topo=-1;
    printf("Enter expression: ");
    scanf("%s", exp);

    for (int i=0; exp[i]; i++) {
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num*10 + (exp[i]-'0');
                i++;
            }
            i--;
            values[++topv] = num;
        }
        else if (exp[i]=='(') {
            ops[++topo] = exp[i];
        }
        else if (exp[i]==')') {
            while (topo!=-1 && ops[topo] != '(') {
                int b = values[topv--];
                int a = values[topv--];
                char op = ops[topo--];
                values[++topv] = apply(a,b,op);
            }
            topo--;
        }
        else {
            while (topo!=-1 && prec(ops[topo]) >= prec(exp[i])) {
                int b = values[topv--];
                int a = values[topv--];
                char op = ops[topo--];
                values[++topv] = apply(a,b,op);
            }
            ops[++topo] = exp[i];
        }
    }

    while (topo!=-1) {
        int b = values[topv--];
        int a = values[topv--];
        char op = ops[topo--];
        values[++topv] = apply(a,b,op);
    }

    printf("Result = %d\n", values[topv]);
    return 0;
}