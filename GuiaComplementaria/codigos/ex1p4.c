while(read(fd_read, &c, 1) == 1){
    write(fd_write, &c, 1);
}

exit(0);
}