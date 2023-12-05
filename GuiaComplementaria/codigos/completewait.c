int stat_val;
pid_t child_pid;

child_pid = wait(&stat_val);

printf("Child has finished: PID = %d\n", child_pid);
if(WIFEXITED(stat_val))
printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
else
printf("Child terminated abnormally\n");