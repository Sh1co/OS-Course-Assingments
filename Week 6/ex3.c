#include <stdio.h>

int processes[10000][4];
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
        processes[i][3] = burstTime;
    }

    //running the processes
    int currentTime=0;

    float totalTaT=0,totalWT=0;

    int cnt=0,doneSth=0;

    while(cnt<n){
        doneSth=0;
        for(int i=0;i<n;i++){
            if(processes[i][1]>0&&currentTime>=processes[i][0]){
                doneSth=1;
                processes[i][1]--;
                currentTime++;
                if(processes[i][1]==0){
                    cnt++;
                    printf("Process #%d \n",processes[i][2]);
                    printf("Completion time :%d \n",(currentTime));
                    printf("Turn around time :%d \n",(currentTime-processes[i][0]));
                    printf("Waiting time :%d \n",(currentTime-processes[i][0]-processes[i][3]));
                    totalTaT+=(currentTime-processes[i][0]);
                    totalWT+=(currentTime-processes[i][0]-processes[i][3]);
                }
            }
        }
        if(!doneSth&&cnt<n)currentTime++;
    }
    totalTaT/=n;
    totalWT/=n;
    printf("Average Turnaround time :%f \n",totalTaT);
    printf("Average waiting time :%f \n",totalWT);
}
