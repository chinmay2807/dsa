#include <stdio.h>
#include <stdlib.h>
struct node{
    int key;
    struct node *left, *right;
};
struct node* newNode(int item){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
int search(struct node *root, int x){
    if( root == NULL)
   return NULL;
    if (x == root->key)
    return root->key;
    if (x < root->key)
    return search(root->left,x);
    if( x > root->key)
    return search(root->right,x);
}
struct node* minValueNode(struct node* node){
    struct node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
struct node* insert(struct node* node, int key){
    if (node == NULL)
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
struct node* deleteNode(struct node* root, int key){
    if (root == NULL)
        return root;
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
void inorder(struct node* root){
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
int main() {
    struct node *root=NULL;
    // printf("enter the root of the bst:");
    // scanf("%d",&root);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\nenter the number to be inserted:");
    int num;
    scanf("%d",&num);
    root = insert(root,num);
    printf("Inorder Traversal:\n");
    inorder(root);
    printf("\nenter the key to be deleted:");
    scanf("%d",&num);
    root = deleteNode(root,num);
    printf("Inorder Traversal:\n");
    inorder(root);
    return 0;
}