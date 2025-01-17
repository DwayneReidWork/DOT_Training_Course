#include <pthread.h> /*pthread not included standard in windows*/
#include <stdio.h>

void* myThread(void* arg)
{
    printf("Thread is running!\n");
    return NULL;
}

int main()
{
    pthread_t;
    pthread_create(&thread, NULL, myThread, NULL);
    pthread_join(thread, NULL);
    return 0;
}