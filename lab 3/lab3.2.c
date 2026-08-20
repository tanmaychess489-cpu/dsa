#include<stdio.h>
int rearrange(int arr[],int n){
    int i,j;
    for(i=0;i<n;i++){
        int key=arr[i];
        j=i-1;
        if(key<0){
        while(j>=0&&arr[j]>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        }
    

    }
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
    rearrange(arr,n);
    printf("rearranged array is:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}