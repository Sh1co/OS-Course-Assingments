#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdlib.h>

int main(){
int myfd = open("hello.txt", O_RDWR);
if (myfd<0) { perror("hello.txt open"); exit(EXIT_FAILURE); };
struct stat mystat = {};
if (fstat(myfd,&mystat)) { perror("fstat"); exit(EXIT_FAILURE); };
off_t myfsz = mystat.st_size;
void*ad = mmap(NULL, myfsz, PROT_READ|PROT_WRITE, MAP_SHARED,
               myfd, 0);
if (ad == MMAP_FAILED) { perror("mmap"); exit(EXIT_FAILURE); };
assert (*(char*ad) == 'H');
((char*)ad) = 'R';
}
