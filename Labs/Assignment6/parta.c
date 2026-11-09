#include "parta.h"
#include <stdio.h>

/**
 * Turn a list of bursts into processes
 * @param bursts list of bursts
 * @param blen length of the list of bursts
 * @return list of processes
 */
struct pcb* init_procs(int* bursts, int blen) {
    struct pcb* processes = malloc(sizeof(struct pcb) * blen);
    for (int i = 0; i < blen; i++) processes[i] = (struct pcb){i, bursts[i], 0};
    return processes;
}

/**
 * Print a list of processes
 * @param procs pointer to processes
 * @param plen length of the list of processes
 */
void printall(struct pcb* procs, int plen) {
    // Feel free to print however you want
    for (int i = 0; i < plen; i++)
        printf("PID: %d | Burst: %d | Wait %d\n\n", procs[i].pid,
               procs[i].burst_left, procs[i].wait);
}

/**
 * TODO: Describe what the function does
 */
void run_proc(struct pcb* procs, int plen, int current, int amount) {
    // TODO: Complete and document
}

/**
 * TODO: Describe what the function does
 */
int fcfs_run(struct pcb* procs, int plen) {
    // TODO: Complete and document
    return -1;
}

/**
 * TODO: Describe what the function does
 */
int rr_next(int current, struct pcb* procs, int plen) {
    // TODO: Complete and document
    return -1;
}
/**
 * TODO: Describe what the function does
 */
int rr_run(struct pcb* procs, int plen, int quantum) {
    // TODO: Complete and document
    return -1;
}

