#include <stdio.h>
void multi(int*,int*);
int main(void){
    int a;
    printf("What is your name?\n");
    scanf("%d",&a);
    printf("your name is %d",a);
    int x=1,y=0;
    multi(&x,&y);
    return 0;
}
void multi(int*  a,int* b){
	printf("%d",(*a)*(*b));
     
}
