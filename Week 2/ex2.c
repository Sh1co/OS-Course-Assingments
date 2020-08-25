#include<stdio.h>

int main(){
    char str[3000];
    scanf("%s",str);
    char rstr[3000];
    for(int i=0;i<strlen(str);i++){
        rstr[i] = str[strlen(str)-i-1];
    }
    printf("%s \n",rstr);
}
