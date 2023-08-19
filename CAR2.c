
#include <stdio.h>
#include <string.h>
int main()
{
    struct car{
        char name[30];
        int year,price;
    };

    struct car s[20];
    int n,a,i,l,j,k=0,cl;
    char c[30];
    printf("How many cars: ");
    scanf("%d",&n);
    printf("which country you want show: ");
    scanf("%s",c);
    cl=strlen(c);
    for(a=0; a<n; a++){
        printf("Input number %d cars manufacturer country name: ",a+1);
        scanf("%s",s[a].name);
        printf("Input number %d cars manufacturer year: ",a+1);
        scanf("%d",&s[a].year);
        printf("Input number %d cars price: ",a+1);
        scanf("%d",&s[a].price);
    }
    for(i=0; i<n; i++){
        for(j=0; j<cl; j++){
            if(s[i].name[j]==c[j]){
                k++;
            }
        }
        if(k==cl){
            printf("%s\n",s[i].name);
            printf("%d\n",s[i].year);
            printf("%d\n",s[i].price);
        }
        k=0;
    }
    return 0;
}
