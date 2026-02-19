
#include <stdio.h>
#include <stdbool.h>
typedef struct
{

    int process_id;
    int burst_time;

    int remaining_time;
    int wt;
    int tat;

} Process;

void scheduling(Process rb[], int size, int time_slice)
{
    int time = 0, done = 0;

    while (done < size)
    {
        for (int i = 0; i < size; i++)
        {
            if (rb[i].remaining_time > 0)
            {
                int exec;

                if (rb[i].remaining_time > time_slice)
                    exec = time_slice;
                else
                    exec = rb[i].remaining_time;

                rb[i].remaining_time -= exec;
                time += exec;

                // Increase waiting time of other processes
                for (int j = 0; j < size; j++)
                {
                    if (j != i && rb[j].remaining_time > 0)
                        rb[j].wt += exec;
                }

                if (rb[i].remaining_time == 0)
                {
                    rb[i].tat = time;
                    done++;
                }
            }
        }
    }

    printf("\nProcess\tWT\tTAT\n");
    for (int i = 0; i < size; i++)
        printf("P%d\t%d\t%d\n", rb[i].process_id, rb[i].wt, rb[i].tat);
}

int main()
{

    Process round_robin[20];

    int number_of_process, time_slice, i;

    printf("Enter number of process ->");
    scanf("%d", &number_of_process);
    printf("\n");

    for (i = 0; i < number_of_process; i++)
    {

        Process node;

        printf("Enter Burst time of process %d -> ", i);
        scanf("%d", &(node.burst_time));

        node.process_id = i;

        round_robin[i] = node;
        round_robin[i].remaining_time = round_robin[i].burst_time;
        round_robin[i].tat = 0;
        round_robin[i].wt = 0;
    }

    printf("\nEnter time slice ->");
    scanf("%d", &time_slice);
    printf("\n");

    scheduling(round_robin, number_of_process, time_slice);

    return 0;
}