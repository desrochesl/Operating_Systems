#include "parta.h"
#include <stdio.h>
#include <stdlib.h>

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
 * Runs the current process and adds wait times to other processes
 * @param procs pointer to processes
 * @param plen length of the list of processes
 * @param current the process selected to run
 * @param amount the burst length
 */
void run_proc(struct pcb* procs, int plen, int current, int amount) {
    for (int i = 0; i < plen; i++) {
        if (procs[i].burst_left == 0)
            continue;
        else if (i == current)
            procs[current] =
                (struct pcb){current, procs[current].burst_left - amount,
                             procs[current].wait};
        else {
            procs[i] =
                (struct pcb){i, procs[i].burst_left, procs[i].wait + amount};
        }
    }
}

/**
 * Use First Come First Serve to run the list of processes
 * @param procs pointer to processes
 * @param plen length of the list of processes
 * @return time length of time the processes ran for
 */
int fcfs_run(struct pcb* procs, int plen) {
    int time = 0;
    for (int i = 0; i < plen; i++) {
        time += procs[i].burst_left;
        run_proc(procs, plen, i, procs[i].burst_left);
    }
    return time;
}

/**
 * Find the next process to run in a Round Robin processing algorithm
 * @param current starting process id
 * @param procs pointer to processes
 * @param plen length of the list of processes
 * @return time length of time the processes ran for
 */
int rr_next(int current, struct pcb* procs, int plen) {
    int next = current;
    for (int i = 0; i < plen; i++) {
        next = (next + 1 < plen) ? next + 1 : 0;
        if (procs[next].burst_left != 0) return next;
    }
    return -1;
}

/**
 * Use Round Robin with a given quantum to run the list of processes
 * @param procs pointer to processes
 * @param plen length of the list of processes
 * @param quantum time before swapping processes
 */
int rr_run(struct pcb* procs, int plen, int quantum) {
    int time = 0;
    int current = 0;
    while (current != -1) {
        int burst = (procs[current].burst_left > quantum)
                        ? quantum
                        : procs[current].burst_left;
        time += burst;
        run_proc(procs, plen, current, burst);
        current = rr_next(current, procs, plen);
    }
    return time;
}
