#include <stdio.h>
int main(){
    char req[]="PEMPWI";
    char frame[3]={'-','-','-'};
    int i,j,hit,faults=0,filled=0;
    for(i=0; req[i]; i++){
        hit=0;
        for(j=0;j<3;j++) if(frame[j]==req[i]) hit=1;
        if(!hit){
            if(filled<3){ frame[filled]=req[i]; filled++; }  // fill empty slot
            else frame[0]=req[i];                             // fixed-slot replace
            faults++;
        }
        printf("%c -> [%c %c %c] %s\n", req[i], frame[0],frame[1],frame[2], hit?"HIT":"PAGE FAULT");
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}
