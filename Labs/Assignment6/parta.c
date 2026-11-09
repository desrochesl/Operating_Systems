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
 * TODO: Describe what the function does
 */
void printall(struct pcb* procs, int plen) {
    // Feel free to print however you want
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

