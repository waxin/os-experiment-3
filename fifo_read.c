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
        char buf[11];
	memset(buf,'\0',sizeof(buf));
        printf("Process %d opening the fifo\n",getpid());
        pipe_fd=open("/tmp/my_fifo1",O_RDONLY);
        if(pipe_fd!=-1){
              	read(pipe_fd,buf,11);
		printf("\nread messege: %s\n",buf);
	}
        else
		exit(EXIT_FAILURE);

}

