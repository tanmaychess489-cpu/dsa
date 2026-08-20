#include<stdio.h>
int main(){
    int m,n;
    printf("enter rows and columns of matrix: ");
    scanf("%d %d",&m,&n);
    int mat[m][n];
    int row[100],col[100],val[100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("enter element: ");
            scanf("%d",&mat[i][j]);
        }
    }
    int x=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]!=0){
                row[x]=i;
                col[x]=j;
                val[x]=mat[i][j];
                x++;
            }
        }
    }
    if(x==0)
    printf("no sparse matrix");
    else{
    printf("sparse matrix:\n");
    for(int i=0;i<x;i++){
        printf("%d %d %d\n",row[i],col[i],val[i]);
    }
}
    return 0;
}