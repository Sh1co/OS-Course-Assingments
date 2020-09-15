#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int cnt = 0;
int printCounter = 0;
int cntMx = 10;
int ok = 1;
int producerAsleep=0;
int consumerAsleep=0;

void *producer(void *vargp)
{
    printf("started producer\n");
    while(1){
        printCounter++;
        if(printCounter>1000){
                printf("1000 iterations complete\n");
                printCounter=0;
        }
        if(cnt==cntMx)producerAsleep=1;
        while(producerAsleep){
            if(producerAsleep&&consumerAsleep){
                printf("dead lock reached\n");
                return 0;
            }
        }
        cnt++;
        if(cnt>0)consumerAsleep = 0;
    }
}

void *consumer(void *vargp)
{
    printf("started consumer\n");
    while(1){
        if(cnt==0)consumerAsleep=1;
        while(consumerAsleep){
            if(producerAsleep&&consumerAsleep){
                printf("dead lock reached\n");
                return 0;
            }
        }
        cnt--;
        if(cnt<cntMx)producerAsleep = 0;
    }
}

int main()
{
    pthread_t tid;
    pthread_t tid1;
    pthread_create(&tid, NULL, producer, (void *)&tid);
    pthread_create(&tid, NULL, consumer, (void *)&tid);
	pthread_exit(NULL);
	return 0;
}
