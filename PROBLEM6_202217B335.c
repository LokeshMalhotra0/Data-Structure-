#include <stdio.h>
#include <conio.h>

void main() {
    int n, a[10], b[10], t[10], w[10], g[10], i;
    float att = 0, awt = 0;

    // Initialize all arrays
    for(i = 0; i < 10; i++) {
        a[i] = 0; 
        b[i] = 0; 
        w[i] = 0; 
        g[i] = 0; 
    }
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    printf("Enter the burst times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    printf("\nEnter the arrival times: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Calculate completion times
    g[0] = a[0] + b[0]; // First process completion time
    for(i = 1; i < n; i++) {
        g[i] = g[i-1] + b[i]; // Subsequent processes completion time
    }
    
    // Calculate waiting times and turnaround times
    for(i = 0; i < n; i++) {
        w[i] = g[i] - a[i] - b[i]; // Waiting time
        t[i] = g[i] - a[i]; // Turnaround time
        awt += w[i]; // Accumulate total waiting time
        att += t[i]; // Accumulate total turnaround time
    }
    
    awt /= n; // Average waiting time
    att /= n; // Average turnaround time
    
    // Display results
    printf("\n\tProcess\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("\tp%d\t\t%d\t\t%d\n", i, w[i], t[i]);
    }
    
    printf("The average waiting time is %.2f\n", awt);
    printf("The average turnaround time is %.2f\n", att);
    
    getch();
}
