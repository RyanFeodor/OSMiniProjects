#include <stdio.h>
#include <pthread.h>
#define N 5
pthread_mutex_t bank[N];

void* pod(void* arg) {
    int id = *(int*)arg;   // dereference the pointer to get the actual id
    int a = id, b = (id+1)%N;
    if (id == N-1) { a = b; b = id; }
    pthread_mutex_lock(&bank[a]); pthread_mutex_lock(&bank[b]);
    printf("Pod %d fast-charging using banks %d & %d\n", id, a, b);
    pthread_mutex_unlock(&bank[b]); pthread_mutex_unlock(&bank[a]);
    return NULL;
}

int main() {
    pthread_t t[N]; int id[N];
    for (int i = 0; i < N; i++) pthread_mutex_init(&bank[i], NULL);
    for (int i = 0; i < N; i++) { id[i] = i; pthread_create(&t[i], NULL, pod, &id[i]); }
    for (int i = 0; i < N; i++) pthread_join(t[i], NULL);
    for (int i = 0; i < N; i++) pthread_mutex_destroy(&bank[i]);
    return 0;
}
