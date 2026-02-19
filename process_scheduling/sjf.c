
#include <stdio.h>

typedef struct
{

    int process_id;
    int burst_time;

} Process;

void heapify_up(Process sjs[], int last_node)
{

    int parent = (last_node - 1) / 2;

    if (last_node > 0 && sjs[last_node].burst_time < sjs[parent].burst_time)
    {

        Process temp = sjs[last_node];
        sjs[last_node] = sjs[parent];

        sjs[parent] = temp;

        heapify_up(sjs, parent);
    }
}
void insert(Process sjs[], Process node, int cur)
{

    sjs[cur] = node;

    heapify_up(sjs, cur);
}

void heapify_down(Process sjs[], int size, int index)
{

    int smallest, left, right;

    smallest = index;
    left = 2 * index + 1;
    right = 2 * index + 2;

    if (left < size && sjs[smallest].burst_time > sjs[left].burst_time)
    {
        smallest = left;
    }

    if (right < size && sjs[smallest].burst_time > sjs[right].burst_time)
    {

        smallest = right;
    }

    if (smallest != index)
    {

        Process temp = sjs[index];

        sjs[index] = sjs[smallest];
        sjs[smallest] = temp;

        heapify_down(sjs, size, smallest);
    }
}

Process extract_min(Process sjs[], int size)
{
    if (size == 1)
    {

        return sjs[0];
    }

    Process res = sjs[0];

    sjs[0] = sjs[size - 1];

    heapify_down(sjs, size - 1, 0);

    return res;
}

void scheduling_sjf(Process sjs[], int size)
{
    Process x;
    int y = size;

    int wt = 0, w = 0;
    int tt = 0, t = 0;
    for (int i = 0; i < y; i++)
    {
        x = extract_min(sjs, size);
        tt += x.burst_time;
        w += wt;
        t += tt;
        printf("Process %d\t%d\t%d\t%d\n", x.process_id, x.burst_time, wt, tt);

        wt += x.burst_time;
        size -= 1;
    }

    printf("Average Waiting Time = %.2f\nAverage Turnaround Time = %.2f\n", (float)w / y, (float)t / y);
}

int main()
{
    Process sjs[20];
    int number_of_process, i;

    printf("Enter number of process -> ");
    scanf("%d", &number_of_process);
    printf("\n");

    for (i = 0; i < number_of_process; i++)
    {
        Process node;

        node.process_id = i;

        printf("\nEnter Burst time for process %d -> ", i);
        scanf("%d", &(node.burst_time));

        insert(sjs, node, i);
    }

    scheduling_sjf(sjs, number_of_process);
    return 0;
}