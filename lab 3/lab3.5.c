#include<stdio.h>
int main(){
    int n;
    printf("enter size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    int left[n],result[n];
    int leftproduct=1;
    for(int i=0;i<n;i++){
        left[i]=leftproduct;
        leftproduct*=arr[i];
    }
    int rightproduct=1;
    for(int i=n-1;i>=0;i--){
        result[i]=rightproduct*left[i];
        rightproduct*=arr[i];
    }
    for(int i=0;i<n;i++){
        printf("%d ",result[i]);
    }
    return 0;
}