//sparse matrix
#include <stdio.h>
int main(){
    int m,n,i,j,mat[30][30];
    printf("Enter the size of matrix: ");
    scanf("%d %d",&m,&n);
    printf("Enter elements of matrix\n: ");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&mat[i][j]);
        }
    }
    int sparse[10][3];
    int k=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(mat[i][j]!=0){
                sparse[k][0]=i;
                sparse[k][1]=j;
                sparse[k][2]=mat[i][j];
                k++;
            }
        }
    }
    printf("Sparse form: ");
    for(i=0;i<k;i++){
        for(j=0;j<3;j++){
            printf("%d\t",sparse[i][j]);
        }
        printf("\n");
    }
}
