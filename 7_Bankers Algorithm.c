#include <pthread.h>
#include <unistd.h>
pthread_mutex_t aisle3=PTHREAD_MUTEX_INITIALIZER, aisle4=PTHREAD_MUTEX_INITIALIZER;
void* robotA(void* a){ pthread_mutex_lock(&aisle3); sleep(1); pthread_mutex_lock(&aisle4); return 0; }
void* robotB(void* a){ pthread_mutex_lock(&aisle4); sleep(1); pthread_mutex_lock(&aisle3); return 0; }
int main(){ pthread_t t1,t2; pthread_create(&t1,0,robotA,0); pthread_create(&t2,0,robotB,0);
 pthread_join(t1,0); pthread_join(t2,0); return 0; }
