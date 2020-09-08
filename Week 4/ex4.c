#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main()
{
    while(1){
        char *buffer;
        size_t bufsize = 50;
        size_t characters;
        buffer = (char *)malloc(bufsize * sizeof(char));
        if( buffer == NULL)
        {
            perror("Unable to allocate buffer");
            exit(1);
        }
        characters = getline(&buffer,&bufsize,stdin);
        if(buffer[characters-1]=='&'){
            int ipid = getpid();
            buffer[characters-1]=' ';
            fork();
            if(ipid==getpid()){
                system(buffer);
            }
        }
        else{
            system(buffer);
        }
    }
}
