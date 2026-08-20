#include<stdio.h>
int maximumprofit(int arr[],int n){
    int min=arr[0];
    int maxprofit=0;
    for(int i=1;i<n;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        else if(arr[i]-min>maxprofit){
            maxprofit=arr[i]-min;
        }
        }
    return maxprofit;
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
    int result=maximumprofit(arr,n);
    printf("maximum profit is:%d",result);
}