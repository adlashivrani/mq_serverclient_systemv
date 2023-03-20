#include "header.h"

int main()
{
    int id;
	struct msg receiver;
    key_t key = 5555;
    if ((id = msgget(key, 0666)) < 0)
    {
       printf("\nError\n");
       exit(1);
    }
	printf("\nWaiting for msgs...\n");
     //Receive an answer of message 
    if (msgrcv(id ,&receiver, MAXSIZE, 1, 0) < 0) {
		printf("\nerror in receiveing msg 1\n");
		exit(1);
	}
	printf("Received msg: %s\n", receiver.buff);
	//msg type of 1
	receiver.mtype = 2;
	printf("\nSend reply .....\n");
	fgets(receiver.buff, MAXSIZE, stdin);
	if (msgsnd(id, &receiver, sizeof(receiver.buff), 0) < 0)
    {
        printf ("Error while seding a message");
        exit(1);
    } else {
        printf("Message Sent\n");
 	}
	printf("sent message: %s\n", receiver.buff);
	msgctl(id, IPC_RMID, NULL);
 	return 0;
}
