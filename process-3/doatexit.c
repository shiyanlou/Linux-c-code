#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void my_exit0(int, void *);
static void my_exit1(void);
static void my_exit2(void);
char str[9]="for test";
int main(void) {
				//char str[9]="for test";
        if (atexit(my_exit2) != 0)
                { perror("can't register my_exit2"); exit(-1); }
        if (atexit(my_exit1) != 0)
                { perror("can't register my_exit1"); exit(-1); }
        if (on_exit(my_exit0,(void *)str) !=0)
        	{ perror("can't register my_exit0"); exit(-1); }
        printf("main is done\n");
        printf("abc");
        //_exit(1234);
        exit(1234);
}

static void my_exit0(int status, void *arg) {
	printf("zero exit handler\n");
	printf("exit %d\n", status);
	printf("arg=%s\n",(char *)arg);
}

static void my_exit1(void) {
        printf("first exit handler\n");
}
static void my_exit2(void)  {
        printf("second exit handler\n");
}
