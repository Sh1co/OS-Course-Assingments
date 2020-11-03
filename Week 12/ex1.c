#include<stdio.h>

int main(){
    char str[20];
    FILE *f = fopen( "/dev/random", "r");
    fread( str,sizeof(char), 20, f);
    fclose(f);
    for(int i=0;i<20;i++)printf("%c",str[i]);
    printf("\n");
}
