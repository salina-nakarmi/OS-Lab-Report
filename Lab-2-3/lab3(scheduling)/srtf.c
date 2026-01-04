#include <stdio.h>

int main() {
    int n, i, j, time = 0, quantum, remain;
    int at[20], bt[20], rt[20], wt[20], tat[20];
    int total_wt = 0, total_tat = 0;
    int gantt[100], gantt_time[100], gantt_count = 0;
    int queue[20], front = 0, rear = 0;
    int visited[20] = {0}, completed[20] = {0};
    float avg_wt, avg_tat;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    remain = n;
    
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining time
    }
    
    printf("Enter Time Quantum: ");
    scanf("%d", &quantum);
    
    // Add first arrived process to queue
    for (i = 0; i < n; i++) {
        if (at[i] == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }
    
    printf("\n======================================");
    printf("\n      ROUND ROBIN SCHEDULING");
    printf("\n======================================\n");
    printf("\nReady Queue Execution:\n");
    
    while (remain > 0) {
        if (front == rear) {
            // No process in queue, advance time
            time++;
            // Check for newly arrived processes
            for (i = 0; i < n; i++) {
                if (at[i] == time && visited[i] == 0) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }
        
        i = queue[front++];
        
        printf("Time %d: Process P%d enters CPU (Remaining: %d)\n", time, i + 1, rt[i]);
        
        // Record for Gantt chart
        gantt[gantt_count] = i;
        gantt_time[gantt_count] = time;
        gantt_count++;
        
        if (rt[i] <= quantum && rt[i] > 0) {
            // Process will complete
            time += rt[i];
            rt[i] = 0;
            completed[i] = 1;
            remain--;
            
            // Calculate times
            tat[i] = time - at[i];
            wt[i] = tat[i] - bt[i];
            total_wt += wt[i];
            total_tat += tat[i];
            
            printf("         P%d completed at time %d\n", i + 1, time);
            
            // Add newly arrived processes to queue
            for (j = 0; j < n; j++) {
                if (at[j] <= time && visited[j] == 0 && completed[j] == 0) {
                    queue[rear++] = j;
                    visited[j] = 1;
                }
            }
        } else if (rt[i] > 0) {
            // Process needs more time
            time += quantum;
            rt[i] -= quantum;
            
            printf("         P%d preempted at time %d (Remaining: %d)\n", i + 1, time, rt[i]);
            
            // Add newly arrived processes to queue first
            for (j = 0; j < n; j++) {
                if (at[j] <= time && visited[j] == 0 && completed[j] == 0) {
                    queue[rear++] = j;
                    visited[j] = 1;
                }
            }
            
            // Add current process back to queue
            queue[rear++] = i;
        }
    }
    
    // Add final time to Gantt chart
    gantt_time[gantt_count] = time;
    
    // Display process details
    printf("\n======================================");
    printf("\n         PROCESS DETAILS");
    printf("\n======================================\n");
    printf("Process\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
    }
    
    avg_wt = (float)total_wt / n;
    avg_tat = (float)total_tat / n;
    
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);
    
    // Display Gantt Chart
    printf("\n======================================");
    printf("\n           GANTT CHART");
    printf("\n======================================\n");
    
    // Top border
    printf(" ");
    for (i = 0; i < gantt_count; i++) {
        printf("--------");
    }
    printf("\n");
    
    // Process names
    printf("|");
    for (i = 0; i < gantt_count; i++) {
        printf("   P%d  |", gantt[i] + 1);
    }
    printf("\n");
    
    // Bottom border
    printf(" ");
    for (i = 0; i < gantt_count; i++) {
        printf("--------");
    }
    printf("\n");
    
    // Time markers
    printf("%d", gantt_time[0]);
    for (i = 1; i <= gantt_count; i++) {
        if (gantt_time[i] < 10) {
            printf("       %d", gantt_time[i]);
        } else {
            printf("      %d", gantt_time[i]);
        }
    }
    printf("\n");
    printf("======================================\n");
    
    return 0;
}