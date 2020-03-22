#include<stdio.h> 
struct process
{
      char pn; int at, bt, ct, wt, tt, pty;
      int status;
}pq[10];
int limit;
void at_Sorting()
{
      struct process temp;
      int i, j;
      for(i = 0; i < limit - 1; i++)
      {
            for(j = i + 1; j < limit; j++)
            {
                  if(pq[i].at > pq[j].at)
                  {
                        temp = pq[i];
                        pq[i] = pq[j];
                        pq[j] = temp;
                  }
            }
      }
}
int main()
{
      int i, time = 0, bt = 0, lt;
      char c;
      float wait_time = 0, tt = 0, awt, att;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      for(i = 0, c = 'A'; i < limit; i++, c++)
      {
            pq[i].pn = c;
            printf("\nEnter Details For Process[%C]:\n", pq[i].pn);
            printf("Enter Arrival Time:\t");
            scanf("%d", &pq[i].at );
            printf("Enter Burst Time:\t");
            scanf("%d", &pq[i].bt);
            printf("Enter pty:\t");
            scanf("%d", &pq[i].pty);
            pq[i].status = 0;
            bt = bt + pq[i].bt;
      }
      at_Sorting();
      pq[9].pty = -9999;
      printf("\nProcess Name\tArrival Time\tBurst Time\tpty\tWaiting Time");
      for(time = pq[0].at; time < bt;)
      {
            lt = 9;
            for(i = 0; i < limit; i++)
            {
                  if(pq[i].at <= time && pq[i].status != 1 && pq[i].pty > pq[lt].pty)
                  {
                        lt = i;
                  }
            }
            time = time + pq[lt].bt;
            pq[lt].ct = time;
            pq[lt].wt = pq[lt].ct - pq[lt].at - pq[lt].bt;
            pq[lt].tt = pq[lt].ct - pq[lt].at;
            pq[lt].status = 1;
            wait_time = wait_time + pq[lt].wt;
            tt = tt + pq[lt].tt;
            printf("\n%c\t\t%d\t\t%d\t\t%d\t\t%d", pq[lt].pn, pq[lt].at, pq[lt].bt, pq[lt].pty, pq[lt].wt);
      }
      awt = wait_time / limit;
      att = tt / limit;
      printf("\n\nAverage waiting time:\t%f\n", awt);
      printf("Average Turnaround Time:\t%f\n", att);
}
