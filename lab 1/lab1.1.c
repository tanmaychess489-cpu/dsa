#include<stdio.h>
int main(){
    int n;
    printf("enter size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
   int pos[n],neg[n],x=0,y=0;
   for(int i=0;i<n;i++){
       if(arr[i]>=0){
           pos[x]=arr[i];
           x++;
       }
       else{
           neg[y]=arr[i];
           y++;
       }
   }
   int p=0,q=0;
   if(x>=y){
    for(int i=0;i<n;i+=2){
        arr[i]=pos[p];
        p++;
    }
    for(int i=1;i<n;i+=2){
        arr[i]=neg[q];
        q++;
    }
   }
   if(y>x){
    for(int i=0;i<n;i+=2){
        arr[i]=neg[q];
        q++;
    }
    for(int i=1;i<n;i+=2){
        arr[i]=pos[p];
        p++;
    }
   }
   for(int i=0;i<n;i++){
       printf("%d ",arr[i]);
   }
   return 0;
}