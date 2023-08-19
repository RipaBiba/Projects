#include <stdio.h>
#include <string.h>
int main()
{
    struct car{
        char name[30];
        int year,price;
    };

    struct car s[20];
    int n,a,i,low,index;
    printf("How many cars: ");
    scanf("%d",&n);
    for(a=0; a<n; a++){
        printf("Input number %d cars name: ",a+1);
        scanf("%s",s[a].name);
        printf("Input number %d cars manufacturer year: ",a+1);
        scanf("%d",&s[a].year);
        printf("Input number %d cars price: ",a+1);
        scanf("%d",&s[a].price);
    }
    low=s[0].price;
    for(i=1; i<n; i++){
        if(s[i].price<s[0].price){
            low=s[i].price;
            index=i;
        }
    }
    printf("%s\n",s[index].name);
}
