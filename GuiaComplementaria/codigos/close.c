#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int filedescriptor = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
    
    if (filedescriptor == -1) {
        perror("Error opening the file");
        return 1;
    }

    write(filedescriptor, "Hello, File Descriptor!\n", 24);

    close(filedescriptor);

    return 0;
}
