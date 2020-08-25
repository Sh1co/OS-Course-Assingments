#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(){
    int i;
    float f;
    double d;
    i = INT_MAX;
    f = FLT_MAX;
    d = DBL_MAX;
    printf("%d : %d\n %G : %d \n %G : %d \n",i,sizeof(i),f,sizeof(f),d,sizeof(d));
}
