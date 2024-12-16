#include <pthread.h>
#include <stdio.h>

pthread_mutex_t lock;
int sharedData =0;

void* incrementData(void* arg)
{
    pthread_mutex_lock(&lock);
    sharedData++;
    printf("Shared Data: %d\n", sharedData);
    pthread_mutex_unluck(&lock);
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;
    pthread_mutex_init(&lock, NULL);
    pthread_crete(&thread1, NULL, incrementData, NULL);
    pthread_crete(&thread2, NULL, incrementData, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_mutex_destroy(&lock);
    return 0;
}