#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "common.h"



long int account_balance = 0;
int threadNum;
pthread_mutex_t lock;
void* increment() {
	long int oneInc = (2048000000/threadNum);
    for (long int i = 0; i < oneInc ; i++) {
    	pthread_mutex_lock(&lock);
        account_balance++;
        pthread_mutex_unlock(&lock);
    }
}

int main(int argc, char* argv[]) {
	double t1 = GetTime();
    threadNum = atoi(argv[1]);
    pthread_t th[threadNum];
    int i;
    for (i = 0; i < threadNum; i++) {
        if (pthread_create(th + i, NULL, &increment, NULL) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        printf("Transaction %d has started\n", i);
    }
    for (i = 0; i < threadNum; i++) {
        if (pthread_join(th[i], NULL) != 0) {
            return 2;
        }
        printf("Transaction %d has finished\n", i);
    }
    printf("Account Balance is : %ld\n", account_balance);
    double t2 = GetTime();
    printf("Time spent: %f ms", (t2-t1)*1000);
    return 0;
}

