#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = top;
    top = t;
}

int pop() {
    if (top == NULL) return -1;
    int v = top->data;
    struct node *t = top;
    top = top->next;
    free(t);
    return v;
}

int peek() {
    if (top == NULL) return -1;
    return top->data;
}

void display() {
    struct node *p = top;
    if (p == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int ch, v;
    while (1) {
        printf("\nChoose:\n");
        printf("1 Push\n");
        printf("2 Pop\n");
        printf("3 Peek\n");
        printf("4 Display\n");
        printf("5 Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &v);
            push(v);
            printf("Pushed %d\n", v);
        } 
        else if (ch == 2) {
            v = pop();
            if (v == -1) printf("Underflow\n");
            else printf("Popped %d\n", v);
        } 
        else if (ch == 3) {
            v = peek();
            if (v == -1) printf("Stack Empty\n");
            else printf("Top = %d\n", v);
        }
        else if (ch == 4) {
            display();
        }
        else if (ch == 5) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}