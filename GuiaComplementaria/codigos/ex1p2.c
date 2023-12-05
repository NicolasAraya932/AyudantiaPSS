int fd_read = open("in.txt", O_RDONLY, S_IRUSR);
int fd_write = open("out.txt", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);