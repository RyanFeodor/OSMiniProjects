#include<stdio.h>
int main(){int n,i,q,t=0,done=0,last=-1,a[20],b[20],p[20],rem[20],wt[20],tat[20];float aw=0,at=0;
printf("Enter Total Number of Flights:");scanf("%d",&n);
for(i=0;i<n;i++){printf("Enter Details of Flight %d\n",i+1);printf("Arrival Time: ");scanf("%d",&a[i]);printf("Burst Time: ");scanf("%d",&b[i]);printf("Priority: ");scanf("%d",&p[i]);rem[i]=b[i];}
printf("Enter Time Quantum:");scanf("%d",&q);
while(done<n){int minp=9999;for(i=0;i<n;i++)if(a[i]<=t&&rem[i]>0&&p[i]<minp)minp=p[i];if(minp==9999){t++;continue;}int idx=-1;for(i=1;i<=n;i++){int j=(last+i)%n;if(a[j]<=t&&rem[j]>0&&p[j]==minp){idx=j;break;}}int run=(rem[idx]>q)?q:rem[idx];t+=run;rem[idx]-=run;last=idx;if(rem[idx]==0){tat[idx]=t-a[idx];wt[idx]=tat[idx]-b[idx];done++;}}
printf("\nFlight  Priority  Burst  Turnaround  Waiting\n");
for(i=0;i<n;i++){printf("%-8d%-10d%-7d%-12d%-8d\n",i+1,p[i],b[i],tat[i],wt[i]);aw+=wt[i];at+=tat[i];}
printf("\nAverage Waiting Time: %.2f\n",aw/n);printf("Average Turnaround Time: %.2f\n",at/n);
return 0;}
