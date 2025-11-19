#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (rear == NULL) {
        front = rear = t;
    } else {
        rear->next = t;
        rear = t;
    }
}

int dequeue() {
    if (front == NULL) return -1;
    int v = front->data;
    struct node *t = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(t);
    return v;
}

int peek() {
    if (front == NULL) return -1;
    return front->data;
}

void display() {
    struct node *p = front;
    if (p == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
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
        printf("1 Enqueue\n");
        printf("2 Dequeue\n");
        printf("3 Peek\n");
        printf("4 Display\n");
        printf("5 Exit\n");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &v);
            enqueue(v);
            printf("Enqueued %d\n", v);
        } 
        else if (ch == 2) {
            v = dequeue();
            if (v == -1) printf("Underflow\n");
            else printf("Dequeued %d\n", v);
        } 
        else if (ch == 3) {
            v = peek();
            if (v == -1) printf("Queue Empty\n");
            else printf("Front = %d\n", v);
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