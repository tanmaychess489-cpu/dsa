#include<stdio.h>
void insert(int arr[],int n,int idx,int key){
    int i=n-2;
    while(i>=idx){
        arr[i+1]=arr[i];
        i--;
    }
    arr[idx]=key;

}
void delete(int arr[],int n,int idx){
    for(int i=idx;i<n-1;i++){
        arr[i]=arr[i+1];

    }

}
void main(){
    int arr[]={1,2,4,5};
    int n=5;
    insert(arr,n,2,3);
    for(int j=0;j<n;j++)
    printf("%d ",arr[j]);
    printf("\n");
    delete(arr,n,1);
    for(int j=0;j<n-1;j++){
        printf("%d ",arr[j]);

    }
}