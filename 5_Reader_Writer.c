#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
sem_t wrt; pthread_mutex_t mx; int score=0, rc=0;
void* player(void* a){ pthread_mutex_lock(&mx); if(++rc==1) sem_wait(&wrt); pthread_mutex_unlock(&mx);
    printf("Player %d sees score=%d\n",*(int*)a,score);
    pthread_mutex_lock(&mx); if(--rc==0) sem_post(&wrt); pthread_mutex_unlock(&mx); return NULL; }
void* server(void* a){ sem_wait(&wrt); score++; printf("Server %d updated score=%d\n",*(int*)a,score); sem_post(&wrt); return NULL; }
int main(){ pthread_t t[7]; int id[5]={1,2,3,4,5}; pthread_mutex_init(&mx,NULL); sem_init(&wrt,0,1);
    for(int i=0;i<5;i++) pthread_create(&t[i],NULL,player,&id[i]);
    for(int i=5;i<7;i++) pthread_create(&t[i],NULL,server,&id[i-5]);
    for(int i=0;i<7;i++) pthread_join(t[i],NULL); }
