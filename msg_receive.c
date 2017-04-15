#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msg_st{
	long int my_msg_type;
	char some_text[BUFSIZ];
};

int main(){
	int running=1;
	int msgid;
	struct my_msg_st some_data;
	long int msg_receive=0;
	msgid=msgget((key_t)1234,0666 | IPC_CREAT);			//建立消息队列并得到其键值
	while(running){
		msgrcv(msgid,(void*)&some_data,BUFSIZ,msg_receive,0);//利用消息队列接受消息
		printf("message received:%s",some_data.some_text);
		if(strncmp(some_data.some_text,"end",3)==0)		//消息是"end"时结束接受过程
			running=0;
	}
}
