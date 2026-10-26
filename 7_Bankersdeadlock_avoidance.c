#include <stdio.h>
int need[2]={4,2}, alloc[2]={0,0}, avail=5;
int safe(int p,int req){ int a=avail-req; return (a>=need[0]-alloc[0]-(p==0?req:0)) || (a>=need[1]-alloc[1]-(p==1?req:0)); }
int main(){ int p=0, req=3;
 if(req<=need[p] && req<=avail && safe(p,req)){ avail-=req; alloc[p]+=req; printf("Granted to robot %d, avail=%d\n",p,avail); }
 else printf("Denied to robot %d - unsafe, avail stays %d\n",p,avail);
 return 0; }
