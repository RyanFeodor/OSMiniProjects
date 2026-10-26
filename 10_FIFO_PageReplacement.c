#include <stdio.h>
int main(){
    char req[]="PEMPWIEMP";
    char frame[3]={'-','-','-'};
    int ptr=0,i,j,hit,faults=0;
    for(i=0; req[i]; i++){
        hit=0;
        for(j=0;j<3;j++) if(frame[j]==req[i]) hit=1;
        if(!hit){
            if(frame[ptr]!='-') printf("Replacing %c with %c (FIFO)\n", frame[ptr], req[i]);
            frame[ptr]=req[i]; ptr=(ptr+1)%3; faults++;
        }
        printf("%c -> [%c %c %c] %s\n", req[i], frame[0],frame[1],frame[2], hit?"HIT":"PAGE FAULT");
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}
