#include <stdio.h>
int main () {
    int burst_time[20],p[20],waiting_time[20],turnAround_time[20],i,j,n,total=0,position,temp;
    float avg_waiting_time,avg_turnAround_time;

    printf("Enter number of process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++) {
        printf("p%d:",i+1);
        scanf("%d",&burst_time[i]);
        p[i]=i+1;         
    }
  
    for(i=0;i<n;i++) {
        position=i;
        for(j=i+1;j<n;j++) {
            if(burst_time[j]<burst_time[position])
                position=j;
        }
        temp=burst_time[i];
        burst_time[i]=burst_time[position];
        burst_time[position]=temp;
        temp=p[i];
        p[i]=p[position];
        p[position]=temp;
    }
   
    waiting_time[0]=0;            
    for(i=1;i<n;i++) {
        waiting_time[i]=0;
        for(j=0;j<i;j++)
            waiting_time[i]+=burst_time[j];
        total+=waiting_time[i];
    }
    avg_waiting_time=(float)total/n;      
    total=0;

    printf("\nProcess\t    Burst Time    \tWaiting Time \tTurnaround Time");
    for(i=0;i<n;i++) {
        turnAround_time[i]=burst_time[i]+waiting_time[i];   
        total+=turnAround_time[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],burst_time[i],waiting_time[i],turnAround_time[i]);
    }
  
    avg_turnAround_time=(float)total/n;    
    printf("\n\nAverage Waiting Time=%f",avg_waiting_time);
    printf("\nAverage Turnaround Time=%f\n",avg_turnAround_time);
}