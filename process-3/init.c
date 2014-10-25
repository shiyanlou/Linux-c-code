#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>

void init_daemon(void)
{
	pid_t pid;
	int i;
	if (pid = fork()){
		/*is parent, close parent*/
		exit(0);
	} else if (pid < 0) {
		/*fork fail*/
		exit(1);
	} else {
		/*first child, and set it be a new group*/
		setsid();
		/*seperate from control terminate*/
		if(pid = fork()) {
			/*is first child, close first child*/
			exit(0);
		} else if (pid < 0) {
			/*fork fail*/
			exit(1);
		} else {
			/*is second child, and do close file*/
			for(i = 0; i < NOFILE; ++i) {
				close(i);
			}
			/*change directory*/
			chdir("/tmp");
			/*clear file mask*/
			umask(0);
	}
	return;
}