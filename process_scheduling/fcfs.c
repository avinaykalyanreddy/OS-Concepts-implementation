// CPU scheduling algorithm First Come First Serve (FCFS

#include <stdio.h>

typedef struct
{
    int processId;
    int burstTime;
} Process;

int calculatingWT(Process *fcfs, int arr_wt[], int size)
{
    int x = 0, i;

    for (int i = 0; i < size; i++)
    {

        arr_wt[i] = x;
        x = x + fcfs->burstTime;

        fcfs += 1;
    }

    return x;
}

int calculatingTAT(Process *fcfs, int arr_TAT[], int size)
{
    int x = 0, i;

    for (i = 0; i < size; i++)
    {

        x = x + fcfs->burstTime;
        arr_TAT[i] = x;

        fcfs += 1;
    }
    return x;
}

int main()
{

    Process fcfs[20];
    int numberOfProcess, i, waitingTime[20], turnAroundTime[20], totalWT = 0, totalTAT = 0;
    printf("Number of process -> ");
    scanf("%d", &numberOfProcess);
    printf("\n");

    for (i = 0; i < numberOfProcess; i++)
    {

        printf("\nEnter Burst time for process %d -> ", i);

        fcfs[i].processId = i;
        scanf("%d", &fcfs[i].burstTime);
    }

    calculatingWT(fcfs, waitingTime, numberOfProcess);
    calculatingTAT(fcfs, turnAroundTime, numberOfProcess);

    printf("Process_ID\tWaiting_Time\t turnAroundTime\n");
    for (i = 0; i < numberOfProcess; i++)
    {

        printf("Process %d\t%d\t\t%d\n", fcfs[i].processId, waitingTime[i], turnAroundTime[i]);
        totalWT += waitingTime[i];
        totalTAT += turnAroundTime[i];
    }

    printf("Average waitingTime -> %.2f\nAverage turnAroundTime -> %.2f", (float)totalWT / numberOfProcess, (float)totalTAT / numberOfProcess);

    return 0;
}
