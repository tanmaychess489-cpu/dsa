#include<stdio.h>
int findduplicate(int arr[],int n){
    int sum1=n*(n-1)/2;
    int sum2=0;
    for(int i=0;i<n;i++){
        sum2+=arr[i];
    }
    return sum2-sum1;
}
void main(){
    int n;
    printf("enter size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    int duplicate=findduplicate(arr,6);
    printf("duplicate element is:%d",duplicate);
}