#include<stdio.h>

void findWaitingTime(int processes[], int p,int bt[], int wt[])
{
	wt[0] = 0;

	for (int i = 1; i < p ; i++ )
		wt[i] = bt[i-1] + wt[i-1] ;
}

void findTurnAroundTime( int processes[], int p,
				int bt[], int wt[], int tat[])
{
	
	for (int i = 0; i < p ; i++)
		tat[i] = bt[i] + wt[i];
}

void findavgTime( int processes[], int p, int bt[])
{
	int wt[p], tat[p], total_wt = 0, total_tat = 0;

    findWaitingTime(processes, p, bt, wt);

	findTurnAroundTime(processes, p, bt, wt, tat);

	printf("Processes  Burst time  Waiting time  Turn around time\n");

	
	for (int i=0; i<p; i++)
	{
		total_wt = total_wt + wt[i];
		total_tat = total_tat + tat[i];
		printf(" %d\t\t%d\t %d\t\t %d\n",i+1,bt[i],wt[i],tat[i]);
	}

	printf("Average waiting time = %f",(float)total_wt / (float)p);
	printf("\nAverage turn around time = %f",(float)total_tat / (float)p);
}

int main()
{
    int p;
    printf("enter the number of processes:::");
    scanf("%d",&p);
    int processes[p];
    int burst_time[p];
    for(int i=1; i<p+1; i++)
        processes[i-1] = i;
    printf("\nenter the burst time for each process respectively->\n");
    for(int i=0; i<p; i++)
        scanf("%d",&burst_time[i]);
        
	findavgTime(processes, p, burst_time);
	return 0;
}
