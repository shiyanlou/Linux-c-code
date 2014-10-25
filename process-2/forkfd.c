#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    int fd, pid, status;
    char buf[10];
    if ((fd = open("./test.txt", O_RDONLY)) < 0) {
        perror("open");  exit(-1);
    }
    if ((pid = fork()) < 0) {
        perror("fork");  exit(-1);
    } else if (pid == 0) {  //child
        read(fd, buf, 2);
        write(STDOUT_FILENO, buf, 2);
    } else {  //parent
        sleep(2);
        lseek(fd, SEEK_CUR, 1);
        read(fd, buf, 3);
        write(STDOUT_FILENO, buf, 3);
        write(STDOUT_FILENO, "\n", 1);
    }
    return 0;
}