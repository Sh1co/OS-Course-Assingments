#include <stdio.h>

int processes[10000][3];
int t[3];

int main(){
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        int arrivalTime,burstTime;
        scanf("%d %d\n",&arrivalTime,&burstTime);
        processes[i][0] = arrivalTime;
        processes[i][1] = burstTime;
        processes[i][2] = i+1;
    }

    //Sorting
    int done =0;
    while(!done){
        done=1;
        for(int i=1;i<n;i++){
            if(processes[i][0]<processes[i-1][0]){
                t[0] = processes[i][0];
                t[1] = processes[i][1];
                t[2] = processes[i][2];
                processes[i][0] = processes[i-1][0];
                processes[i][1] = processes[i-1][1];
                processes[i][2] = processes[i-1][2];
                processes[i-1][0]=t[0];
                processes[i-1][1]=t[1];
                processes[i-1][2]=t[2];
                done =0;
            }
        }
    }

    //running the processes
    int currentTime=0;

    float totalTaT=0,totalWT=0;


    for(int i=0;i<n;i++){
        printf("Process #%d \n",(i+1));
        printf("Completion time :%d \n",((currentTime<processes[i][0]?processes[i][0]:currentTime)+processes[i][1]));
        printf("Turn around time :%d \n",((currentTime<processes[i][0]?0:currentTime-processes[i][0])+processes[i][1]));
        printf("Waiting time :%d \n",((currentTime<processes[i][0]?0:currentTime-processes[i][0])));
        totalTaT+=((currentTime<processes[i][0]?0:currentTime-processes[i][0])+processes[i][1]);
        totalWT+=((currentTime<processes[i][0]?0:currentTime-processes[i][0])+processes[i][1]);
        currentTime = ((currentTime<processes[i][0]?processes[i][0]:currentTime)+processes[i][1]);
    }
    totalTaT/=n;
    totalWT/=n;
    printf("Average Turnaround time :%f \n",totalTaT);
    printf("Average waiting time :%f \n",totalWT);
}
