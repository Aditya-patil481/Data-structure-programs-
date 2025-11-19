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

void print_range(struct node* root, int L, int R) {
    if (!root) return;

    if (root->data > L) print_range(root->left, L, R);

    if (root->data >= L && root->data <= R)
        printf("%d ", root->data);

    if (root->data < R) print_range(root->right, L, R);
}

int main() {
    struct node* root = NULL;
    int ch, x, L, R;

    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1 Insert\n");
        printf("2 Print values in range [L, R]\n");
        printf("3 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2) {
            printf("Enter L: ");
            scanf("%d", &L);
            printf("Enter R: ");
            scanf("%d", &R);
            printf("Values in range [%d, %d]: ", L, R);
            print_range(root, L, R);
            printf("\n");
        }
        else if (ch == 3) break;
    }
    return 0;
}