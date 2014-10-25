#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
        int                     i;
        char            **ptr;
        extern char     **environ;
        for (i = 0; i < argc; i++)              /* echo all command-line args */
                printf("argv[%d]: %s\n", i, argv[i]);
        for (ptr = environ; *ptr != 0; ptr++)   /* and all env strings */
                printf("%s\n", *ptr);
/*        printf("hostname is %s\n", getenv("HOSTNAME"));
        setenv("HOSTNAME", "yangzhu2", 0);
        printf("hostname is %s\n", getenv("HOSTNAME"));
        setenv("HOSTNAME", "yangzhu2", 1);
        printf("hostname is %s\n", getenv("HOSTNAME"));
*/ 
        exit(0);
}
