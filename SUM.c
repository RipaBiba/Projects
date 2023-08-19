#include <stdio.h>
int main()
{
    int c1,c2,r1,r2,m1[10][10],m2[10][10],r[10][10],i,j,k,sum=0;
    printf("Input 1st matrix column and row number: ");
    scanf("%d%d",&c1,&r1);
    printf("Input 2nd matrix column and row number: ");
    scanf("%d%d",&c2,&r2);
    if(c1==r2){
        printf("1st matrix:\n");
        for(i=0;i<c1;i++){
            for(j=0;j<r1;j++){
                scanf("%d",&m1[i][j]);
            }
        }
        printf("2nd matrix:\n");
        for(i=0;i<c2;i++){
            for(j=0;j<r2;j++){
                scanf("%d",&m2[i][j]);
            }
        }
    }
    for(i=0;i<c1;i++){
        for(j=0;j<r2;j++){
            for(k=0;k<r1;k++){
                sum=sum+m1[i][k]*m2[k][j];
            }
            r[i][j]=sum;
            sum=0;
        }
    }
    printf("result\n");
    for(i=0;i<c1;i++){
        for(j=0;j<r2;j++){
            printf("%d",r[i][j]);
            printf("\n");
        }
    }
    return 0;
}
