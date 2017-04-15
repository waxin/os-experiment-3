#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
	int data_processed;
	const char some_data[]="hello pipe";
	int file_pipes[2];
	char buffer[BUFSIZ+1];
	pid_t fork_result;
	memset(buffer,'\0',sizeof(buffer));

	if(pipe(file_pipes)==0){
		fork_result=fork();
		if(fork_result==-1){
			printf("fork failed\n");
			exit(EXIT_FAILURE);
		}
		
		else if(fork_result==0){
			data_processed=write(file_pipes[1],some_data,strlen(some_data));
			printf("son process write :%s\n",some_data);
			exit(EXIT_SUCCESS);
		}
		
		else{
			data_processed=read(file_pipes[0],buffer,sizeof(buffer));
			printf("father process read %d bytes frome the pipe\n:%s\n",data_processed,buffer);
			exit(EXIT_SUCCESS);
		}
	}
	else
		exit(EXIT_FAILURE);
}
