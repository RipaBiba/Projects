#include <stdio.h>
#include <string.h>
int main()
{
    struct student{
        char name[30];
        int age;
        float cgpa;
    };

    struct student s[20];
    int n,a,i,old;
    printf("How many students: ");
    scanf("%d",&n);
    for(a=0; a<n; a++){
        printf("Input number %d students name: ",a+1);
        scanf("%s",s[a].name);
        printf("Input number %d students age: ",a+1);
        scanf("%d",&s[a].age);
        printf("Input number %d students cgpa: ",a+1);
        scanf("%f",&s[a].cgpa);
    }
    old=s[0].age;
    for(i=0; i<n; i++){
        if(s[i].age>old){
            old=s[i].age;
        }
    }
    for(a=0; a<n; a++){
        if(s[a].age==old){
            printf("%s\n",s[a].name);
        }
    }
}
