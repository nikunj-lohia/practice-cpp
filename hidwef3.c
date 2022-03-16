#include <stdio.h>

int main() {

    int arrival_time[10], b[10], burst_time[10], turnAround_time[10], waiting_time[10], i, j, s, count=0, time, n;
    double avg=0, tt=0, end;

    printf ("enter the number of Processes ");
    scanf ("%d", &n); 
    printf ("enter arrival time\n");
    for (i=0; i<n; i++)
        scanf ("%d", &arrival_time[i]);
    printf ("enter burst time\n");
    for(i=0; i<n; i++)
        scanf("%d", &b[i]); 
    for(i=0; i<n; i++)
        burst_time[i] = b[i];

    b[9] = 100;
    for (time=0; count!=n; time++) {
        s = 9;
        for(i=0; i<n; i++) {
            if(arrival_time[i]<=time && b[i]<b[s] && b[i]>0 )
                s = i;
        }
        b[s]--;
        if(b[s] == 0) {
            count++;
            end = time + 1;
            waiting_time[s] = end - arrival_time[s] - burst_time[s];
            avg = avg + end - arrival_time[s] - burst_time[s];
            tt = tt + end - arrival_time[s];
        }
    }

    printf("\nProcess\t    Arrival Time\t  Burst Time \tWaiting Time \tTurnaround Time");
    for (i=0; i<n; i++) {
        turnAround_time[i] = burst_time[i] + waiting_time[i];
        printf ("\np%d\t\t  %d\t\t  %d\t\t    %d\t\t\t%d", i+1, arrival_time[i], burst_time[i], waiting_time[i], turnAround_time[i]);
    }

    printf("\n\nAverage waiting time = %lf\n", avg/n);
    printf("Average Turnaround time = %lf", tt/n);
    
    return 0;
}