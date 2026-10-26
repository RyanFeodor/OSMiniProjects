#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t lock; int completed=0;
void* assay(void* id){ printf("Sample %ld viability test running...\n",(long)id); sleep(1); pthread_mutex_lock(&lock); printf("Samples Completed=%d\n",++completed); pthread_mutex_unlock(&lock); return 0; }
int main(){
pthread_t t[8]; pthread_mutex_init(&lock,0);
for(long i=0;i<8;i++) pthread_create(&t[i],0,assay,(void*)i);
for(int i=0;i<8;i++) pthread_join(t[i],0);
pthread_mutex_destroy(&lock);}
