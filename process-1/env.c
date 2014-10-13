#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[], char *envp[])
{
        char **ptr;
        for (ptr = envp; *ptr != 0; ptr++)   /* and all env strings */
                printf ("%s\n", *ptr);

        printf ("\n\n--------My environment variable-------\n\n");
        printf ("USERNAME is %s\n", getenv("USERNAME"));
        putenv ("USERNAME=shiyanlou");
        printf ("USERNAME is %s\n", getenv("USERNAME"));
        setenv ("USERNAME", "shiyanlou-2", 0);
        printf ("USERNAME is %s\n", getenv("USERNAME"));
        setenv ("USERNAME", "shiyanlou-2", 1);
        printf ("USERNAME is %s\n", getenv("USERNAME"));
 
	return 0;
}

