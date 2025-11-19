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

int find_min(struct node* root) {
    if (!root) return -1;
    while (root->left) root = root->left;
    return root->data;
}

int find_max(struct node* root) {
    if (!root) return -1;
    while (root->right) root = root->right;
    return root->data;
}

int main() {
    struct node* root = NULL;
    int ch, x;

    while (1) {
        printf("\n--- BST Menu ---\n");
        printf("1 Insert\n");
        printf("2 Find Minimum\n");
        printf("3 Find Maximum\n");
        printf("4 Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter value: ");
            scanf("%d", &x);
            root = insert(root, x);
        }
        else if (ch == 2) {
            x = find_min(root);
            if (x == -1) printf("Tree is empty\n");
            else printf("Minimum = %d\n", x);
        }
        else if (ch == 3) {
            x = find_max(root);
            if (x == -1) printf("Tree is empty\n");
            else printf("Maximum = %d\n", x);
        }
        else if (ch == 4) break;
    }
    return 0;
}