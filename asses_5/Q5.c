#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node *createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *insertLevelOrder(int arr[], struct node *root, int i, int n) {
    if (i < n) {
        struct node *temp = createNode(arr[i]);
        root = temp;
        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);
        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}
void preorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    printf("%d->", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}
void inorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d->", root->data);
    inorderTraversal(root->right);
}
void postorderTraversal(struct node *root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d->", root->data);
}
int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct node *root = NULL;
    root = insertLevelOrder(arr, root, 0, n);
    int i=1;
    while (i) {
            printf("\nenter the choice 0-exit 1-inorder 2-preorder 3-postorder \n");
            scanf("%d", &i);
        switch (i) {
            case 0:
                return 0;
            case 1:
                printf("inorder traversal of the given array is:\n");
                inorderTraversal(root);
            break;
            case 2:
                printf("preorder traversal of the given array is:\n");
                preorderTraversal(root);
            break;
            case 3:
                printf("postorder traversal of the given array is:\n");
                postorderTraversal(root);
            break;
            default:
                printf("wrong input\n");
            break;
        }
    }
}
