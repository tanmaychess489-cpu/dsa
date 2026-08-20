#include<stdio.h>
void findsubsets(int arr[],int n,int index,int target,int subset[],int size){
    if(target==0){
        for(int i=0;i<size;i++){
            printf("%d ",subset[i]);
        }
        printf("\n");
        return;
    }
    if(target<0||index==n){
        return;
    }
subset[size]=arr[index];
findsubsets(arr,n,index+1,target-arr[index],subset,size+1);
findsubsets(arr,n,index+1,target,subset,size);
}
int main(){
    int n,target;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter target sum: ");
    scanf("%d",&target);
    int subset[n];
    findsubsets(arr,n,0,target,subset,0);
    return 0;
}