#include<stdio.h>


int dlMat[5][5];

int main(){
    int e[3];
    int a[3];
    int c[5][3];
    int r[5][3];

    scanf("%d %d %d",&e[0],&e[1],&e[2]);
    scanf("%d %d %d",&a[0],&a[1],&a[2]);

    for(int i=0;i<5;i++){
        scanf("%d %d %d",&c[i][0],&c[i][1],&c[i][2]);
    }

    for(int i=0;i<5;i++){
        scanf("%d %d %d",&r[i][0],&r[i][1],&r[i][2]);
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(i==j)continue;
            for(int k=0;k<3;k++){
                if(r[i][k]>a[k]&&r[i][k]<=a[k]+c[j][k]){
                    dlMat[i][j]=1;
                    dlMat[j][i]=1;
                }
            }
        }
    }
    int fnd = 0;
    for(int i=0;i<4;i++){
        for(int j=i+1;j<5;j++){
            if(dlMat[i][j]){
                printf("%d %d\n",(i+1),(j+1));
                fnd=1;
            }
        }
    }
    if(!fnd){
        printf("no deadlock is detected\n");
    }
}
