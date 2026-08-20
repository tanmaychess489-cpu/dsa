#include<stdio.h>
void insertionsort(int arr[],int n){
    int i,j;
    for(int i=1;i<n;i++){
        int key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void bubblesort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void main(){
    int arr1[]={2,4,3,7,6,11,14,18,15,16,80};
    int arr2[]={2,4,3,7,6,11,14,18,15,16,80};
    int n=11;
    insertionsort(arr1,n);
    printf("insertion sort:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr1[i]);
    }
    printf("\n");
    bubblesort(arr2,n);
    printf("bubble sort:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr2[i]);
    }
}