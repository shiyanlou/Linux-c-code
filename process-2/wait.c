#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
void pr_exit(int status);
int  main(void)
{
        pid_t   	    pid;
        int             status;
        if ( (pid = fork()) < 0)
                { perror("fork"); exit(-1); }
        else if (pid == 0) {             /* child */
                sleep(1);
                printf("in child\n");
                exit(101);
        }   
        if (wait(&status) != pid)               /* wait for child */
                { perror("wait"); exit(-2); }
        printf("in parent\n");
        pr_exit(status);                           /* and print its status */
        if ( (pid = fork()) < 0)
                { perror("fork"); exit(-1); }
        else if (pid == 0)              /* child */
                abort();                    /* generates SIGABRT */        
	if (wait(&status) != pid)               /* wait for child */
                { perror("wait"); exit(-2); }
        pr_exit(status);                                /* and print its status */
        if ( (pid = fork()) < 0)
                { perror("fork"); exit(-1); }
        else if (pid == 0)              /* child */
                status /= 0;            /* divide by 0 generates SIGFPE */
        if (wait(&status) != pid)               /* wait for child */
                { perror("wait"); exit(-1); }
        pr_exit(status);                                /* and print its status */
        exit(0);
}
void pr_exit(int status) {
	if (WIFEXITED(status))
		printf("normally termination, low-order 8 bit of exit status = %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormally termination, singal number = %d\n", WTERMSIG(status));
}
