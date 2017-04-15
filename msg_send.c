#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 512

struct my_msg_st{
        long int my_msg_type;
        char some_text[MAX];
};

int main(){
        int running=1;
        int msgid;
        struct my_msg_st some_data;
	char buf[BUFSIZ];
        msgid=msgget((key_t)1234,0666 | IPC_CREAT);                     //建立消息队列并得到其键值
        while(running){
		printf("messge sended :");
		fgets(buf,BUFSIZ,stdin);
		some_data.my_msg_type=1;
		strcpy(some_data.some_text,buf);
                msgsnd(msgid,(void*)&some_data,MAX,0);//利用消息队列传送消息
                if(strncmp(some_data.some_text,"end",3)==0)             //消息是"end"时结束接受过程
                        running=0;
        }
}

