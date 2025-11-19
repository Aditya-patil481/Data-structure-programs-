#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* head = NULL;
struct node* head2 = NULL;

struct node* create() {
    struct node *h = NULL, *t, *last = NULL;
    int n, x;
    printf("How many nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &x);
        t = malloc(sizeof(struct node));
        t->data = x;
        t->next = NULL;
        if (h == NULL) h = last = t;
        else {
            last->next = t;
            last = t;
        }
    }
    printf("List created\n");
    return h;
}

void display(struct node *p) {
    if (!p) {
        printf("List is empty\n");
        return;
    }
    printf("List: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

struct node* insert_beg(struct node *h, int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = h;
    h = t;
    printf("Inserted\n");
    return h;
}

struct node* insert_end(struct node *h, int x) {
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = NULL;
    if (!h) {
        printf("Inserted\n");
        return t;
    }
    struct node *p = h;
    while (p->next) p = p->next;
    p->next = t;
    printf("Inserted\n");
    return h;
}

struct node* insert_pos(struct node *h, int pos, int x) {
    if (pos == 1) return insert_beg(h, x);
    struct node *p = h;
    for (int i = 1; p && i < pos - 1; i++) p = p->next;
    if (!p) {
        printf("Invalid position\n");
        return h;
    }
    struct node *t = malloc(sizeof(struct node));
    t->data = x;
    t->next = p->next;
    p->next = t;
    printf("Inserted\n");
    return h;
}

struct node* delete_beg(struct node *h) {
    if (!h) {
        printf("Empty\n");
        return h;
    }
    struct node *t = h;
    h = h->next;
    free(t);
    printf("Deleted\n");
    return h;
}

struct node* delete_end(struct node *h) {
    if (!h) {
        printf("Empty\n");
        return h;
    }
    if (!h->next) {
        free(h);
        printf("Deleted\n");
        return NULL;
    }
    struct node *p = h;
    while (p->next->next) p = p->next;
    free(p->next);
    p->next = NULL;
    printf("Deleted\n");
    return h;
}

struct node* delete_pos(struct node *h, int pos) {
    if (pos == 1) return delete_beg(h);
    struct node *p = h;
    for (int i = 1; p && i < pos - 1; i++) p = p->next;
    if (!p || !p->next) {
        printf("Invalid position\n");
        return h;
    }
    struct node *t = p->next;
    p->next = t->next;
    free(t);
    printf("Deleted\n");
    return h;
}

struct node* reverse(struct node *h) {
    struct node *p = h, *q = NULL, *r = NULL;
    while (p) {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    printf("Reversed\n");
    return q;
}

void find_middle(struct node *h) {
    struct node *s = h, *f = h;
    if (!h) {
        printf("Empty\n");
        return;
    }
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
    }
    printf("Middle = %d\n", s->data);
}

struct node* sort(struct node *h) {
    if (!h) return h;
    for (struct node *i = h; i; i = i->next)
        for (struct node *j = i->next; j; j = j->next)
            if (i->data > j->data) {
                int t = i->data;
                i->data = j->data;
                j->data = t;
            }
    printf("Sorted\n");
    return h;
}

void detect_loop(struct node *h) {
    struct node *s = h, *f = h;
    while (f && f->next) {
        s = s->next;
        f = f->next->next;
        if (s == f) {
            printf("Loop detected\n");
            return;
        }
    }
    printf("No loop\n");
}

void sum_list(struct node *h) {
    int s = 0;
    while (h) {
        s += h->data;
        h = h->next;
    }
    printf("Sum = %d\n", s);
}

void odd_even(struct node *h) {
    printf("Odd: ");
    for (struct node *p = h; p; p = p->next)
        if (p->data % 2 != 0) printf("%d ", p->data);
    printf("\nEven: ");
    for (struct node *p = h; p; p = p->next)
        if (p->data % 2 == 0) printf("%d ", p->data);
    printf("\n");
}

struct node* merge(struct node *a, struct node *b) {
    if (!a) return b;
    if (!b) return a;
    struct node *c, *last;
    if (a->data < b->data) {
        c = last = a;
        a = a->next;
    }
    else {
        c = last = b;
        b = b->next;
    }
    while (a && b) {
        if (a->data < b->data) {
            last->next = a;
            last = a;
            a = a->next;
        }
        else {
            last->next = b;
            last = b;
            b = b->next;
        }
    }
    if (a) last->next = a;
    if (b) last->next = b;
    printf("Merged\n");
    return c;
}

int main() {
    int ch, x, pos;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1 Create\n2 Insert Beg\n3 Insert End\n4 Insert Pos\n");
        printf("5 Delete Beg\n6 Delete End\n7 Delete Pos\n8 Reverse\n");
        printf("9 Find Middle\n10 Sort\n11 Detect Loop\n12 Sum\n");
        printf("13 Print Odd-Even\n14 Display\n15 Create 2nd List\n16 Merge Lists\n17 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) head = create();
        else if (ch == 2) {
            printf("Value: ");
            scanf("%d",&x);
            head = insert_beg(head,x);
        }
        else if (ch == 3) {
            printf("Value: ");
            scanf("%d",&x);
            head = insert_end(head,x);
        }
        else if (ch == 4) {
            printf("Position and value: ");
            scanf("%d%d",&pos,&x);
            head = insert_pos(head,pos,x);
        }
        else if (ch == 5) head = delete_beg(head);
        else if (ch == 6) head = delete_end(head);
        else if (ch == 7) {
            printf("Position: ");
            scanf("%d",&pos);
            head = delete_pos(head,pos);
        }
        else if (ch == 8) head = reverse(head);
        else if (ch == 9) find_middle(head);
        else if (ch == 10) head = sort(head);
        else if (ch == 11) detect_loop(head);
        else if (ch == 12) sum_list(head);
        else if (ch == 13) odd_even(head);
        else if (ch == 14) display(head);
        else if (ch == 15) head2 = create();
        else if (ch == 16) head = merge(head, head2);
        else if (ch == 17) break;
    }
    return 0;
}