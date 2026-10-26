#include <stdio.h>
int main(){
    char assets[]="PEMWI";       // asset load requests
    char queue[5]; int front=0, rear=0, n=0;
    int i;
    for(i=0; assets[i]; i++){
        queue[rear]=assets[i]; rear=(rear+1)%5; n++;   // enqueue
        printf("Loaded %c into queue\n", assets[i]);
    }
    printf("Processing order (FIFO):\n");
    while(n>0){
        printf("Removing %c from queue\n", queue[front]);
        front=(front+1)%5; n--;
    }
    return 0;
}
