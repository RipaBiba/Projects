#include <stdio.h>
#include <math.h>

int isPrimeCount(int p){
    int a,c=0;
    for(a=2;a<p;a++){
        if(p % a == 0){
            c++;
           break;
        }
    }
    if (c == 1){
        return p;
    }
    else{
        return 0;
    }
    return 1;
}
 int main(){
    int n,r;
    printf("Enter an integer: \n");
    scanf("%d",&n);
    r = isPrimeCount(n);
    if (n == 1) {
        printf("\n1 is neither prime nor composite.");
    }
    else if (r == 1){
        printf("%d is Prime number \n",n);
    }
    else{
        printf("%d is not Prime number \n",n);
    }

    return 0;
}
