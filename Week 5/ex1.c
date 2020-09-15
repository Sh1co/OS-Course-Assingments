#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int cnt = 0;
int ok = 1;

void *Threader(void *vargp)
{
	printf("This is thread #%d \n",cnt);
	ok=1;
}

int main()
{

    int n;
    scanf("%d",&n);
    pthread_t tid;

	for (int i = 0; i < n; i++){
        while(!ok);
        ok = 0;
        printf("Thread #%d got created \n",++cnt);
		pthread_create(&tid, NULL, Threader, (void *)&tid);
	}

	pthread_exit(NULL);
	return 0;
}
