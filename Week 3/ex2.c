#include <stdio.h>

void  bubble_sort(int arr[],int n){
    int done = 0;
    while(!done){
        done = 1;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                int t = arr[i];
                arr[i] = arr[i+1];
                arr[i+1]=t;
                done =0;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[10000];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,n);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
