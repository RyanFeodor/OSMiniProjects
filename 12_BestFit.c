#include <stdio.h>
int main(){
    int blk[4]={150,100,250,60};
    char task[4][5]={"NAV","COM","SEN","LIFE"};
    int need[4]={120,80,200,50};
    int i,j,m;
    printf("SPACECRAFT MEMORY - BEST FIT\n\n");
    for(i=0;i<4;i++){
        m=-1;
        for(j=0;j<4;j++) if(blk[j]>=need[i] && (m==-1||blk[j]<blk[m])) m=j;
        if(m!=-1){ printf("%-4s (%dMB) -> Block %dMB (idx%d)\n", task[i],need[i],blk[m],m); blk[m]-=need[i]; }
        else printf("%-4s (%dMB) -> UNALLOCATED\n", task[i],need[i]);
    }
    return 0;
}
