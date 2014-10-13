#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf ("pid = %d\n", pid);
    printf ("ppid = %d\n", ppid);

    return 0;
}
