#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{

	pid_t child[argc];

	char const *archivos = *argv+1;

	for(int i = 0; i < argc ; i++)
	{
		child[i] = fork();
		if(child[i] == 0)
		{
				execlp("gcc", "gcc", "-c", archivos[i], NULL);
		}
		for(int i = 0; i < argc ; i++){
			waitpid(child[i], NULL, 0);
		}
	}
		
		return 0;
}
