#include<stdio.h>

int main(int argc, char *argv[]){
    //printf("%d\n",argc);
    FILE *f = fopen( "/dev/stdin", "r");
    char etc[20000];
    char ch;
    if(argc==3&&argv[1][0]=='-'&&argv[1][1]=='a'){
        FILE *f2 = fopen( argv[2], "a");
        while( ( ch = fgetc(f) ) != EOF ){
                fputc(ch, f2);
                printf("%c",ch);
        }
        fclose(f2);
    }
    else if(argc==2){
        FILE *f2 = fopen( argv[1], "w");
        while( ( ch = fgetc(f) ) != EOF ){
                fputc(ch, f2);
                printf("%c",ch);
        }
        fclose(f2);
    }
    else{
        printf("argument error\n");
    }
    fclose(f);
}
