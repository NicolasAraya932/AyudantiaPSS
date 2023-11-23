#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void tree(const char *path, int profundidad)
{
	DIR *dir;
	struct dirent *entry;

	if(!(dir = opendir(path)))
	{
		perror("NO SE PUDO ABRIR DIR");
		return;
	}

	while((entry = readdir(dir)) != NULL)
	{
		if(entry->d_type == DT_DIR) {
			if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			{
				continue;
			}

			for(int i = 0; i < profundidad; ++i)
			{
				printf("-");
			}
			printf("[%s]\n", entry->d_name);

			char pathBuf[1024];
			snprintf(pathBuf, sizeof(pathBuf), "%s/%s", path, entry->d_name);
			tree(pathBuf, profundidad + 1);
		}
		else{
			for(int i = 0; i < profundidad; ++i)
			{
				printf("-");
				printf("%s\n", entry->d_name);
			}
		}
	}
}


int main()
{
	const char *rootPath = ".";
	tree(rootPath, 0);


	return 0;
}
