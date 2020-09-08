#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    while(1){
        char command[50];
        scanf("%s\n", command);
        system(command);
    }
}
