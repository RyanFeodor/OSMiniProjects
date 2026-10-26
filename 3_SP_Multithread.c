#define _GNU_SOURCE
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
float d[5];
void* c(void* a){
int id=*(int*)a;
d[id]=10+rand()%20;
printf("Sensor %d (Thread %d) reading: %.2fC\n",id,id+1,d[id]);
return NULL;}
int main(){
pthread_t t[5];
int ids[5]={0,1,2,3,4};
for(int i=0;i<5;i++)
pthread_create(&t[i],NULL,c,&ids[i]);
for(int i=0;i<5;i++)
pthread_join(t[i],NULL);
float avg=0;
for(int i=0;i<5;i++)
avg+=d[i];
avg/=5;
printf("Predicted next reading (avg): %.2fC\n",avg);
return 0;}
