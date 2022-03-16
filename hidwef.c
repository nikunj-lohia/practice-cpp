#include<stdio.h>
 
int main() {
    int n,burst_time[20],waiting_time[20],turnaround_time[20],i,j;
    float av_wt=0,av_tat=0;

    printf("Enter total number of processes(maximum 20):");
    scanf("%d",&n);
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++) {
        printf("P[%d]:",i+1);
        scanf("%d",&burst_time[i]);
    }
 
    waiting_time[0]=0;   
    for(i=1;i<n;i++) {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
    }
 
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++) {
        turnaround_time[i]=burst_time[i]+waiting_time[i];
        av_wt+=waiting_time[i];
        av_tat+=turnaround_time[i];
        printf("\n   P%d\t\t   %d\t\t   %d\t\t   %d",i+1,burst_time[i],waiting_time[i],turnaround_time[i]);
    }
 
    av_wt/=i;
    av_tat/=i;
    printf("\n\nAverage Waiting Time:%f",av_wt);
    printf("\nAverage Turnaround Time:%f",av_tat);
 
    return 0;
}