#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* create_node(int x) {
    struct node* t = malloc(sizeof(struct node));
    t->data = x;
    t->left = t->right = NULL;
    return t;
}

struct node* insert(struct node* root, int x) {
    if (!root) return create_node(x);
    if (x < root->data) root->left = insert(root->left, x);
    else if (x > root->data) root->right = insert(root->right, x);
    return root;
}

void inorder(struct node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct node* root) {
    if (!root) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

struct queue {
    struct node* a[1000];
    int f, r;
};

void enqueue(struct queue *q, struct node *x) {
    q->a[++q->r] = x;
}
int empty(struct queue *q) {
    return q->f == q->r;
}
struct node* dequeue(struct queue *q) {
    return q->a[++q->f];
}

void bfs(struct node* root) {
    if (!root) {
        printf("Tree is empty\n");
        return;
    }
    struct queue q;
    q.f = q.r = -1;
    enqueue(&q, root);
    printf("Level Order: ");
    while (!empty(&q)) {
        struct node* t = dequeue(&q);
        printf("%d ", t->data);
        if (t->left) enqueue(&q, t->left);
        if (t->right) enqueue(&q, t->right);
    }
    printf("\n");
}

struct node* mirror(struct node* root) {
    if (!root) return root;
    struct node *l = mirror(root->left);
    struct node *r = mirror(root->right);
    root->left = r;
    root->right = l;
    return root;
}

struct node* search(struct node* root, int x) {
    if (!root || root->data == x) return root;
    if (x < root->data) return search(root->left, x);
    return search(root->right, x);
}

struct node* parent(struct node* root, int x) {
    if (!root) return NULL;
    if ((root->left && root->left->data == x) || (root->right && root->right->data == x))
        return root;
    if (x < root->data) return parent(root->left, x);
    return parent(root->right, x);
}

void children(struct node* root, int x) {
    struct node* t = search(root, x);
    if (!t) {
        printf("Node not found\n");
        return;
    }
    printf("Children of %d: ", x);
    if (!t->left && !t->right) {
        printf("None\n");
        return;
    }
    if (t->left) printf("%d ", t->left->data);
    if (t->right) printf("%d ", t->right->data);
    printf("\n");
}

void sibling(struct node* root, int x) {
    struct node* p = parent(root, x);
    if (!p) {
        printf("No sibling\n");
        return;
    }
    printf("Sibling of %d: ", x);
    if (p->left && p->right) {
        if (p->left->data == x) printf("%d\n", p->right->data);
        else printf("%d\n", p->left->data);
    } else printf("None\n");
}

void gp(struct node* root, int x) {
    struct node* p = parent(root, x);
    if (!p) {
        printf("No grandparent\n");
        return;
    }
    struct node* g = parent(root, p->data);
    printf("Grandparent of %d: ", x);
    if (!g) printf("None\n");
    else printf("%d\n", g->data);
}

void uncle(struct node* root, int x) {
    struct node* p = parent(root, x);
    if (!p) {
        printf("No uncle\n");
        return;
    }
    struct node* g = parent(root, p->data);
    if (!g) {
        printf("No uncle\n");
        return;
    }
    printf("Uncle of %d: ", x);
    if (g->left && g->right) {
        if (g->left->data == p->data) printf("%d\n", g->right->data);
        else printf("%d\n", g->left->data);
    } else printf("None\n");
}

int main() {
    struct node* root = NULL;
    int ch, x;

    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1 Insert\n");
        printf("2 Inorder Traversal\n");
        printf("3 Preorder Traversal\n");
        printf("4 Postorder Traversal\n");
        printf("5 Level Order (BFS)\n");
        printf("6 Mirror Tree\n");
        printf("7 Children of Node\n");
        printf("8 Sibling of Node\n");
        printf("9 Parent of Node\n");
        printf("10 Grandparent of Node\n");
        printf("11 Uncle of Node\n");
        printf("12 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2) {
            printf("Inorder: ");
            inorder(root);
            printf("\n");
        }
        else if (ch == 3) {
            printf("Preorder: ");
            preorder(root);
            printf("\n");
        }
        else if (ch == 4) {
            printf("Postorder: ");
            postorder(root);
            printf("\n");
        }
        else if (ch == 5) bfs(root);
        else if (ch == 6) {
            root = mirror(root);
            printf("Tree mirrored\n");
        }
        else if (ch == 7) {
            printf("Enter node: ");
            scanf("%d", &x);
            children(root, x);
        }
        else if (ch == 8) {
            printf("Enter node: ");
            scanf("%d", &x);
            sibling(root, x);
        }
        else if (ch == 9) {
            printf("Enter node: ");
            scanf("%d", &x);
            struct node* p = parent(root, x);
            if (!p) printf("No parent\n");
            else printf("Parent: %d\n", p->data);
        }
        else if (ch == 10) {
            printf("Enter node: ");
            scanf("%d", &x);
            gp(root, x);
        }
        else if (ch == 11) {
            printf("Enter node: ");
            scanf("%d", &x);
            uncle(root, x);
        }
        else if (ch == 12) break;
    }
    return 0;
}