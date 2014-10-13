#include <stdio.h>
#include <stdlib.h>

int global_init_val = 100;
int global_noninit_val;
extern char **environ;

int main(int argc, char *argv[], char *envp[])
{
     static int localstaticval = 10;
     char *localval;
     localval = malloc(10);
     printf("address of text  is : %p\n", main);
     printf("address of data  is : %p, %p\n", &global_init_val, &localstaticval);
     printf("address of bss   is : %p\n", &global_noninit_val);
     printf("address of heap  is : %p\n", localval);
     printf("address of stack is : %p\n", &localval);
     free(localval);

     printf("&environ = %p, environ = %p\n", &envp, envp);
     printf("&argv = %p, argv = %p\n", &argv, argv);
     return 0;
}
