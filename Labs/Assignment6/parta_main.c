#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parta.h"

/**
 * Calculate the average wait time for processes
 * @param procs pointer to processes
 * @param plen length of the list of processes
 * @return average wait time as float
 */
float avg_wait(struct pcb* procs, int plen) {
    float wait = 0;
    for (int i = 0; i < plen; i++) {
        wait += procs[i].wait;
    }
    float avg = wait / plen;
    return avg;
}

/**
 * Helper method to print errors
 */
int err() {
    fprintf(stderr, "ERROR: Missing arguments\n");
    return 1;
}

int main(int argc, char* argv[]) {
    if (argc < 3) return err();
    int quantum = 0;
    char* mode = argv[1];
    bool isRR = strcmp(mode, "rr");
    int start = 2;
    if (!isRR) {
        quantum = atoi(argv[2]);
        start++;
        if (argc < 4) return err();
        printf("Using RR(%d)\n\n", quantum);
    } else
        printf("Using FCFS\n\n");

    int plen = argc - start;
    int* bursts = malloc(plen * sizeof(int));

    for (int i = 0; i < plen; i++) bursts[i] = atoi(argv[i + start]);

    struct pcb* procs = init_procs(bursts, plen);

    for (int i = 0; i < plen; i++)
        printf("Accepted P%d: Burst %d\n", procs[i].pid, procs[i].burst_left);

    if (!isRR)
        rr_run(procs, plen, quantum);
    else
        fcfs_run(procs, plen);

    printf("Average wait time: %.2f", avg_wait(procs, plen));

    free(procs);
    free(bursts);
    return 0;
}
