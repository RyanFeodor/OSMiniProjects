#include<stdio.h>
int main(){int n,i,t=0,done=0,a[20],b[20],p[20],rem[20],wt[20],tat[20];float aw=0,at=0;
printf("Enter Total Number of Flights:");scanf("%d",&n);
for(i=0;i<n;i++){printf("Enter Details of Flight %d\n",i+1);printf("Arrival Time: ");scanf("%d",&a[i]);printf("Burst Time: ");scanf("%d",&b[i]);printf("Priority: ");scanf("%d",&p[i]);rem[i]=b[i];}
while(done<n){int idx=-1,minp=9999;for(i=0;i<n;i++)if(a[i]<=t&&rem[i]>0&&p[i]<minp){minp=p[i];idx=i;}if(idx==-1){t++;continue;}rem[idx]--;t++;if(rem[idx]==0){tat[idx]=t-a[idx];wt[idx]=tat[idx]-b[idx];done++;}}
printf("\nFlight  Arrival  Burst  Priority  Turnaround  Waiting\n");
for(i=0;i<n;i++){printf("%-8d%-9d%-7d%-10d%-12d%-8d\n",i+1,a[i],b[i],p[i],tat[i],wt[i]);aw+=wt[i];at+=tat[i];}
printf("\nAverage Waiting Time: %.2f\n",aw/n);printf("Average Turnaround Time: %.2f\n",at/n);
return 0;}
