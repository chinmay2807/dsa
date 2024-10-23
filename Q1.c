#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
void printll(struct node* n) {
    int i=0;
    while(n!=NULL) {
        printf("%d(x^%d)+ ", n->data,i++);
        n=n->next;
    }
    printf("\n");
}
struct node* makell(int a[][2],int b[][2],int sa,int sb,int size) {
    struct node* temp=malloc(sizeof(struct node));
    struct node *head = temp;
    temp->data=0;
    temp->next=NULL;
    for(int i=0;i<size;i++) {
        struct node* temp2=malloc(sizeof(struct node));
        temp2->data=0;
        temp->next=temp2;
        temp2->next=NULL;
        temp=temp->next;
    }

    for(int i=0;i<sa;i++) {
        struct node *temp=head;
        for(int j=0;j<a[i][1];j++) {
            temp=temp->next;
        }
        temp->data=a[i][0];
    }
    for(int i=0;i<sb;i++) {
        struct node*temp=head;
        for(int j=0;j<b[i][1];j++) {
            temp=temp->next;
        }
        temp->data+=b[i][0];
    }
    return head;
}
int main() {
    printf("enter the number of terms in the polynomial1:");
    int size1;
    scanf("%d",&size1);
    int arr1[size1][2];
    printf("enter the elements of the linked list:");
    for(int i=0;i<size1;i++) {
            for (int j=0;j<2;j++) {
                scanf("%d",&arr1[i][j]);
            }
    }
    int max1=0;
    for(int i=0;i<size1;i++) {
        max1=max1>arr1[i][1]?max1:arr1[i][1];
    }
    printf("enter the number of terms in the polynomial2:");
    int size2;
    scanf("%d",&size2);
    int arr2[size2][2];
    printf("enter the elements of the linked list:");
    for(int i=0;i<size2;i++) {
        for (int j=0;j<2;j++) {
            scanf("%d",&arr2[i][j]);
        }
    }
    int max2=0;
    for(int i=0;i<size2;i++) {
        max2=max2>arr2[i][1]?max2:arr2[i][1];
    }
    int max=max1>max2?max1:max2;
    struct node * head=makell(arr1,arr2,size1,size2,max+1);
    printll(head);
}