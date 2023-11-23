#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>

void listDirectory(const char *path, int depth) {
    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            // Print nombre de directorio con identacion segun profundidad
            for (int i = 0; i < depth; ++i)
                printf("  ");
            printf("[%s]\n", entry->d_name);

            // Listar de forma recursiva los subdirectorios
            char pathBuf[1024];
            snprintf(pathBuf, sizeof(pathBuf), "%s/%s", path, entry->d_name);
            listDirectory(pathBuf, depth + 1);
        } else {

            for (int i = 0; i < depth; ++i)
                printf("  ");
            printf("%s\n", entry->d_name);
        }
    }

    closedir(dir);
}

int main() {
    const char *rootPath = "."; // Change this to the directory you want to start listing
    listDirectory(rootPath, 0);

    return 0;
}

