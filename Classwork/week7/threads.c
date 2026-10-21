#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *rtn_main()
{
    // Malloc int (must outlive this function, so it can't be a local variable)
    int *pday = malloc(sizeof(int));
    *pday = 28;
    // Return pointer, exit
    pthread_exit(pday);
}
int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, rtn_main, NULL);
    // Receive pointer
    int *rtn = NULL;
    pthread_join(tid, (void **)&rtn);
    printf("day=%d\n", *rtn);
    free(rtn);
    rtn = NULL;
    return 0;
}
