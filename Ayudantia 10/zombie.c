#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	pid_t pid;
	char *message;
	int n;

	printf("wena init");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("Error fork");
			exit(1);
		case 0:
			message = "child";
			n = 3;
			break;
		default:
			message = "parent";
			n = 5;
			break;
	}

	for(;n > 0;n--){
		puts(message);
		sleep(1);
	}
}
