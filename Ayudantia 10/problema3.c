#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

struct sigaction sig1, sig2, sig3;

void ctrl_c(){
	sigaction(SIGINT, &sig2, NULL);

	printf("En 5 segundos chao\n");
	alarm(5);
	pause();
	alarm(0);
}

void ctrl_c2(){
	printf("Estoy en ctrl2");
	sleep(10);
	sigaction(SIGINT, &sig1, NULL);
}

void alarma(){
	printf("LENTO\n");
	exit(1);
}


int main(){
	setvbuf(stdout, NULL, _IONBF, 0);

	sig1.sa_handler = ctrl_c;
	sig1.sa_flags = SA_NODEFER;


	sig2.sa_handler = ctrl_c2;
	sig2.sa_flags = 0;

	sig3.sa_handler = alarma;
	sig1.sa_flags = SA_NODEFER;


	sigaction(SIGINT, &sig1, NULL);
	sigaction(SIGALRM, &sig2, NULL);

	for(int i = 0; i < 10000; i++)
	{
		for(int k = 0 ; k < 100 ; k++){
			printf("\b \b");
		}

		printf("%d", i);
		sleep(1);
	}


	return 0;
}
