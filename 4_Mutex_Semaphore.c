#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t incubator; pthread_mutex_t lock; int completed=0;
void* assay(void* id){ sem_wait(&incubator); printf("Sample %ld loaded into incubator\n",(long)id); sleep(1); pthread_mutex_lock(&lock); printf("Samples Completed=%d\n",++completed); pthread_mutex_unlock(&lock); sem_post(&incubator); return 0; }
int main(){
pthread_t t[8]; sem_init(&incubator,0,3); pthread_mutex_init(&lock,0);
for(long i=0;i<8;i++) pthread_create(&t[i],0,assay,(void*)i);
for(int i=0;i<8;i++) pthread_join(t[i],0);
sem_destroy(&incubator); pthread_mutex_destroy(&lock);}
