#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(){
	int pipe_fd;
	int res;
	const char hello[]="hello fifo";
	mkfifo("/tmp/my_fifo1",0777);
	printf("Process %d opening the fifo\n",getpid());
	pipe_fd=open("/tmp/my_fifo1",O_WRONLY);
	if(pipe_fd!=-1)
		write(pipe_fd,hello,10);
	else
		exit(EXIT_FAILURE);
}
