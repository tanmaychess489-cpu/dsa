#include<stdio.h>
int slargest(int arr[],int n){
    int max1=arr[0];
    int max2=arr[1];
    if(max2>max1){
        int temp=max2;
        max2=max1;
        max1=temp;
    }
    for(int i=2;i<n;i++){
        if(arr[i]>max1){
            max2=max1;
            max1=arr[i];
        }
        else if(arr[i]>max2&&arr[i]<max1){
            max2=arr[i];
        }
    }
    return max2;
}
int ssmallest(int arr[],int n){
    int min1=arr[0];
    int min2=arr[1];
    if(min2<min1){
        int temp=min2;
        min2=min1;
        min1=temp;
    }
    for(int i=2;i<n;i++){
        if(arr[i]<min1){
            min2=min1;
            min1=arr[i];
        }
        else if(arr[i]<min2&&arr[i]>min1){
            min2=arr[i];
        }
    }
    return min2;
}
    

void main(){
    int n;
    printf("enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    int z=slargest(arr,n);
    int x=ssmallest(arr,n);
    printf("second largest element is:%d\n",z);
    printf("second smallest element is:%d",x);
    
}
    