#include<stdio.h>
void main(){
    int n;
    printf("enter size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("enter element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    int freq[n],unique[n],freqcount=1,x=0;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1]){
            freqcount++;
        }
        else{
            freq[x]=freqcount;
            unique[x]=arr[i-1];
            x++;
            freqcount=1;
        }
    }
    freq[x]=freqcount;
    unique[x]=arr[n-1];
    x++;
for(int i=0;i<x;i++){
        printf("element %d has frequency %d\n",unique[i],freq[i]);
    }
}
