#include <stdio.h>
#define NM(c) (c=='S'?"Song":c=='A'?"Album":c=='P'?"Playlist":c=='R'?"Recently Played":"Downloaded")
int main(){
    char ref[]="SAPSARD", frame[3]={'-','-','-'};
    int freq[3]={0,0,0}, i,j,hit,m;
    for(i=0; ref[i]; i++){
        hit=0;
        for(j=0;j<3;j++) if(frame[j]==ref[i]){ hit=1; freq[j]++; }
        if(!hit){
            m=-1;
            for(j=0;j<3;j++) if(frame[j]=='-'){ m=j; break; }
            if(m==-1){ m=0; for(j=1;j<3;j++) if(freq[j]<freq[m]) m=j; }
            if(frame[m]!='-') printf("%s(%c) evicts %s(%c)\n", NM(ref[i]),ref[i], NM(frame[m]),frame[m]);
            frame[m]=ref[i]; freq[m]=1;
        }
        printf("%s(%c) -> [%c %c %c] %s\n", NM(ref[i]),ref[i], frame[0],frame[1],frame[2], hit?"HIT":"PAGE FAULT");
    }
    return 0;
}

