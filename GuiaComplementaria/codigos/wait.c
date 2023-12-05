#include <sys/types.h>
#include <sys/wait.h>

pid_t wait(int *stat_loc);

/*----------------------------------------*/

int status;
wait(&status);