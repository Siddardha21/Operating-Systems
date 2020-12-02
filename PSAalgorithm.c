#include<stdio.h>

int main() {

int bursttime[100], waitingtime[100], tat[100], i, n;
float waitingtimeavg, tatavg;

printf("\nEnter the number of processes: ");
scanf("%d", &n);

for(i=0;i<n;i++) {

printf("\nEnter Burst Time for Process %d: ", i);
scanf("%d", &bursttime[i]);

}
waitingtime[0] = waitingtimeavg = 0;
tat[0] = tatavg = bursttime[0];
for(i=1;i<n;i++) {

waitingtime[i] = waitingtime[i-1] +bursttime[i-1];
tat[i] = tat[i-1] +bursttime[i];
waitingtimeavg = waitingtimeavg + waitingtime[i];
tatavg = tatavg + tat[i];

}

printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\n");
for(i=0;i<n;i++)
printf("\n\t P%d \t\t %d \t\t %d \t\t %d\n\n", i, bursttime[i], waitingtime[i], tat[i]);
printf("\nAverage Waiting Time: %f", waitingtimeavg);
printf("\nAverage Turnaround Time: %f\n\n", tatavg);

}
