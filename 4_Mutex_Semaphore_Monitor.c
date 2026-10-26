#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t incubator; pthread_mutex_t lock; pthread_cond_t cond; int busy=0,completed=0;
void* assay(void* id){ sem_wait(&incubator); pthread_mutex_lock(&lock); while(busy) pthread_cond_wait(&cond,&lock); busy=1; printf("Analyzing Sample %ld\n",(long)id); sleep(1); printf("Samples Completed=%d\n",++completed); busy=0; pthread_cond_signal(&cond); pthread_mutex_unlock(&lock); sem_post(&incubator); return 0; }
int main(){
pthread_t t[8]; sem_init(&incubator,0,3); pthread_mutex_init(&lock,0); pthread_cond_init(&cond,0);
for(long i=0;i<8;i++) pthread_create(&t[i],0,assay,(void*)i);
for(int i=0;i<8;i++) pthread_join(t[i],0);
sem_destroy(&incubator); pthread_mutex_destroy(&lock); pthread_cond_destroy(&cond);}
