#include<stdio.h>


void defNotSwap(int *x, int *y){
    int z = *y;
    *y = *x;
    *x = z;
}


int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    defNotSwap(&x,&y);
    printf("%d %d\n",x,y);
}
