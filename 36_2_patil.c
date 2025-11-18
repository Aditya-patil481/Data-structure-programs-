#include <stdio.h>

int main() {
    int a[100], n, front = -1, rear = -1, ch, v, i;
    printf("Enter queue size: ");
    scanf("%d", &n);
    while (1) {
        printf("\n1 Enqueue\n2 Dequeue\n3 Front\n4 Display\n5 Is Empty\n6 Is Full\n7 Size\n8 Exit\nChoose: ");
        scanf("%d", &ch);
        if (ch == 1) {
            if (rear == n - 1) printf("Queue Full\n");
            else {
                printf("Enter value: ");
                scanf("%d", &v);
                if (front == -1) front = 0;
                rear++;
                a[rear] = v;
                printf("Enqueued %d\n", v);
            }
        } else if (ch == 2) {
            if (front == -1 || front > rear) printf("Queue Empty\n");
            else {
                printf("Dequeued %d\n", a[front]);
                front++;
            }
        } else if (ch == 3) {
            if (front == -1 || front > rear) printf("Queue Empty\n");
            else printf("Front: %d\n", a[front]);
        } else if (ch == 4) {
            if (front == -1 || front > rear) printf("Queue Empty\n");
            else {
                printf("Queue: ");
                for (i = front; i <= rear; i++) printf("%d ", a[i]);
                printf("\n");
            }
        } else if (ch == 5) {
            if (front == -1 || front > rear) printf("Yes, queue is empty\n");
            else printf("No, queue is not empty\n");
        } else if (ch == 6) {
            if (rear == n - 1) printf("Yes, queue is full\n");
            else printf("No, queue is not full\n");
        } else if (ch == 7) {
            if (front == -1 || front > rear) printf("Current size: 0\n");
            else printf("Current size: %d\n", rear - front + 1);
        } else if (ch == 8) {
            break;
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}