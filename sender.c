#include "header.h"

int main()
{
	key_t key = 5555;
    int id;
	struct msg sender;	
    
    if ((id = msgget(key, IPC_CREAT | 0666 )) < 0)
    {
      	printf("\nError in creating\n"); 
        exit(1);
    }
	//msg type
	sender.mtype = 1;
    printf("Enter a message:");
 	fgets(sender.buff, MAXSIZE, stdin);

    if (msgsnd(id, &sender, sizeof(sender.buff), 0) < 0)
    {
        printf ("Error while seding a message");
        exit(1);
    } else {
        printf("Message Sent\n");
	}
	printf("sent message: %s\n", sender.buff);
//	bzero(sender.buff, MAXSIZE);
	printf("\nwainting for reply....\n");
	if (msgrcv(id ,&sender, MAXSIZE, 2, 0) < 0) {
        printf("\nerror in receiveing msg \n");
        exit(1);
 	}
	printf("\nReceived msg :\n %s\n", sender.buff);
	return 0;   
}
