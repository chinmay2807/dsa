#include <stdio.h>
#include<stdlib.h>

void swap(int *x,int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}
int findMax(int A[],int n){
    int max=100;
    int i;
    for(i=0;i<n;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}
void CountSort(int A[],int n){
    int i,j,max,*C;
    max=findMax(A,n);
    C=(int *)malloc(sizeof(int)*(max+1));
    for(i=0;i<max+1;i++){
        C[i]=0;
    }
    for(i=0;i<n;i++){
        C[A[i]]++;
    }
    i=0;j=0;
    while(j<max+1){
        if(C[j]>0){
            A[i++]=j;
            C[j]--;
        }
        else
            j++;
    }
}
int main(){
  printf("Enter sizeo of array:");
  int n;
  scanf("%d",&n);
  int A[n];
    printf("Enter array elements:");
  for(int i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
    CountSort(A,n);
    for(int i=0;i<n;i++)
        printf("%d ",A[i]);
    printf("\n");
    return 0;
 }