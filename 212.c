#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
pthread_mutex_t m;
int g = 10;

void* f()
{
    int i = 0;
    for(i = 0; i < 10; i++)
    {
        pthread_mutex_lock(&m);
        g++;
        printf("g = %d\n", g);
        pthread_mutex_unlock(&m);
    }
}

int main()
{
    pthread_mutex_init(&m, NULL);
    pthread_t t1, t2, t3;
    pthread_create(&t1, NULL, f, NULL);
    pthread_create(&t2, NULL, f, NULL);
    pthread_create(&t3, NULL, f, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_mutex_destroy(&m);
    return 0;
}