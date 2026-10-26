#include<stdio.h>
int main(){int n,i,q,t,c=0,a[20],b[20],rem[20],wt[20],tat[20],queue[1000],front=0,rear=0,inq[20]={0};float aw=0,at=0;
printf("Enter Total Number of Flights:");scanf("%d",&n);
for(i=0;i<n;i++){printf("Enter Details of Flight %d\n",i+1);printf("Arrival Time: ");scanf("%d",&a[i]);printf("Burst Time: ");scanf("%d",&b[i]);rem[i]=b[i];}
printf("Enter Time Quantum:");scanf("%d",&q);queue[rear++]=0;inq[0]=1;t=a[0];
while(c<n){int idx=queue[front++];int run=(rem[idx]>q)?q:rem[idx];t+=run;rem[idx]-=run;for(i=0;i<n;i++)if(a[i]<=t&&!inq[i]&&i!=idx){queue[rear++]=i;inq[i]=1;}if(rem[idx]>0)queue[rear++]=idx;else{tat[idx]=t-a[idx];wt[idx]=tat[idx]-b[idx];c++;}}
printf("\nFlight  Burst Time  Turnaround Time  Waiting Time\n");
for(i=0;i<n;i++){printf("%-8d%-12d%-17d%-12d\n",i+1,b[i],tat[i],wt[i]);aw+=wt[i];at+=tat[i];}
printf("\nAverage Waiting Time: %.2f\n",aw/n);printf("Average Turnaround Time: %.2f\n",at/n);
return 0;}
