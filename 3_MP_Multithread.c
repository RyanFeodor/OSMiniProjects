#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#define S 3
#define M 3
const char* nm[M]={"Temperature","Wind Speed","Cloud Height"};
float lo[M]={10,0,500},hi[M]={30,60,5000},d[S];int mid;
void* rd(void* a){int id=*(int*)a;d[id]=lo[mid]+((float)rand()/RAND_MAX)*(hi[mid]-lo[mid]);printf("%s S%d T%d: %.2f\n",nm[mid],id,id+1,d[id]);return 0;}
int main(){int pf[M][2];
for(int m=0;m<M;m++){pipe(pf[m]);
if(!fork()){srand(getpid());mid=m;pthread_t t[S];int ix[S];
for(int i=0;i<S;i++){ix[i]=i;pthread_create(&t[i],0,rd,&ix[i]);}
for(int i=0;i<S;i++)pthread_join(t[i],0);
float a=0;
for(int i=0;i<S;i++)a+=d[i];a/=S;write(pf[m][1],&a,4);exit(0);}}
for(int m=0;m<M;m++){float a;read(pf[m][0],&a,4);printf("%s -> %.2f\n",nm[m],a);wait(0);}}
