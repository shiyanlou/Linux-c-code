#include <stdio.h>
#include <sys/select.h>
#include <fcntl.h>
#include <unistd.h>

#define MAXNUM      100
#define OPEN_DEV    "/dev/input/mice"

int main(void)
{
    fd_set rfds;
    struct timeval tv;
    int retval, fd;
    char buf[MAXNUM];

    fd = open(OPEN_DEV, O_RDONLY);
    while (1) {
        FD_ZERO(&rfds);
        FD_SET(0, &rfds);
        FD_SET(fd, &rfds);
        tv.tv_sec = 5;
        tv.tv_usec = 0;

        retval = select(fd+1, &rfds, NULL, NULL, &tv);
        if (retval < 0)
            printf ("error\n");
        if (retval == 0)
            printf ("No data within 5 seconds\n");
        if (retval > 0) {
            if (FD_ISSET(0, &rfds)) {
                printf ("Data is available from keyboard now\n");
                read(0, buf, MAXNUM);
            }
            if (FD_ISSET(fd, &rfds)) {
                printf ("Data is available from mouse now\n");
                read(fd, buf, MAXNUM);
            }
        }
    }
    return 0;
}
