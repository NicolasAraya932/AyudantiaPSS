#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

void cat(const char *filePath){
	int file = open(filePath, O_RDONLY);
	if(file == -1)
	{
		perror("ERROR ABRIENDO FILE");
		exit(EXIT_FAILURE);
	}

	char BUFFER[BUFFER_SIZE];
	ssize_t bytesRead;
	
	while((bytesRead = read(file, BUFFER, sizeof(BUFFER))) > 0)
	{
		if(write(1, BUFFER, bytesRead) != bytesRead){
			perror("ERROR PRINTING IN STDOUT");
			close(file);
			exit(EXIT_FAILURE);
		}
	}
	if(bytesRead == -1)
	{
		perror("ERROR LEYENDO FILE");
		close(file);
		exit(EXIT_FAILURE);
	}

	close(file);
}


int main(int argc, char *argv[])
{
	if(argc < 2) {
		fprintf(stderr, "Modo de uso: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (int i = 1; i < argc; ++i)
	{
		cat(argv[i]);
	}
	
	return 0;
}
