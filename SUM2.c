#include <stdio.h>
int main()
{
    int s,m[10][10],i,j,sum=0;
    printf("Input square matrix column and row number: ");
    scanf("%d",&s);
    printf("Matrix:\n");
    for(i=0;i<s;i++){
        for(j=0;j<s;j++){
            scanf("%d",&m[i][j]);
        }
    }
    for(i=0;i<s;i++){
        sum=sum+m[i][i];
        printf("+ %d ",m[i][i]);
    }
    printf("= %d",sum);
    return 0;
}
