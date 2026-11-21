
#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateFCFS(struct Process p[], int n) {
    int totalWaiting = 0;
    int totalTurnaround = 0;

    printf("\n===== FCFS SCHEDULING =====\n");
    printf("Process\tBurst\tWaiting\tTurnaround\n");

    p[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        p[i].waitingTime =
            p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime =
            p[i].waitingTime + p[i].burstTime;

        totalWaiting += p[i].waitingTime;
        totalTurnaround += p[i].turnaroundTime;

        printf("P%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].burstTime,
               p[i].waitingTime,
               p[i].turnaroundTime);
    }

    printf("Average Waiting Time: %.2f\n",
           (float)totalWaiting / n);

    printf("Average Turnaround Time: %.2f\n",
           (float)totalTurnaround / n);
}

void calculateSJF(struct Process p[], int n) {
    struct Process temp;
    int totalWaiting = 0;
    int totalTurnaround = 0;

    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].burstTime > p[j + 1].burstTime) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    p[0].waitingTime = 0;

    for (int i = 1; i < n; i++) {
        p[i].waitingTime =
            p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    printf("\n===== SJF SCHEDULING =====\n");
    printf("Process\tBurst\tWaiting\tTurnaround\n");

    for (int i = 0; i < n; i++) {
        p[i].turnaroundTime =
            p[i].waitingTime + p[i].burstTime;

        totalWaiting += p[i].waitingTime;
        totalTurnaround += p[i].turnaroundTime;

        printf("P%d\t%d\t%d\t%d\n",
               p[i].id,
               p[i].burstTime,
               p[i].waitingTime,
               p[i].turnaroundTime);
    }

    printf("Average Waiting Time: %.2f\n",
           (float)totalWaiting / n);

    printf("Average Turnaround Time: %.2f\n",
           (float)totalTurnaround / n);
}

int main() {
    struct Process processes[20];
    struct Process sjfProcesses[20];

    int n;

    printf("===== CPU SCHEDULING SIMULATOR =====\n");

    printf("Enter number of processes (1-20): ");
    scanf("%d", &n);

    if (n < 1 || n > 20) {
        printf("Invalid number of processes.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;

        printf("Enter burst time for P%d: ", i + 1);
        scanf("%d", &processes[i].burstTime);

        if (processes[i].burstTime <= 0) {
            printf("Burst time must be positive.\n");
            return 1;
        }

        sjfProcesses[i] = processes[i];
    }

    calculateFCFS(processes, n);
    calculateSJF(sjfProcesses, n);

    return 0;
}
