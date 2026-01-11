#include <stdio.h>

int main() {
    int n, i, time = 0, smallest, count = 0, end;
    int at[20], bt[20], rt[20], wt[20], tat[20];
    int total_wt = 0, total_tat = 0;
    int gantt[100], gantt_time[100], gantt_count = 0;
    float avg_wt, avg_tat;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter Arrival Time for Process %d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Remaining time initially equals burst time
    }
    
    // Find the process with maximum burst time to set end time
    rt[19] = 9999; // A large value for comparison
    
    int prev_process = -1; // Track previous process for Gantt chart
    
    for (time = 0; count != n; time++) {
        smallest = 19;
        
        // Find process with shortest remaining time
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0) {
                smallest = i;
            }
        }
        
        // If a different process is selected, add to Gantt chart
        if (smallest != 19 && smallest != prev_process) {
            gantt[gantt_count] = smallest;
            gantt_time[gantt_count] = time;
            gantt_count++;
            prev_process = smallest;
        }
        
        // Execute the process for 1 time unit
        if (smallest != 19) {
            rt[smallest]--;
            
            // If process completes
            if (rt[smallest] == 0) {
                count++;
                end = time + 1;
                wt[smallest] = end - bt[smallest] - at[smallest];
                tat[smallest] = end - at[smallest];
                
                total_wt += wt[smallest];
                total_tat += tat[smallest];
            }
        }
    }
    
    // Add final time to Gantt chart
    gantt_time[gantt_count] = time;
    
    // Display process details
    printf("\nProcess\tArrival\tBurst\tWaiting\tTurnaround\n");
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