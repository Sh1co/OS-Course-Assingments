#include<stdio.h>



int *reallocer(int *ptr, size_t size){
    int *ret;
    ret =(int*) malloc(size);
    int n = sizeof(ptr[0])/sizeof(ptr);
    n = (size<n)?size:n;
    for(int i=0;i<n;i++){
            ret[i] = ptr[i];
    }
    free(ptr);
    return ret;
}


int main(){

}
