//Kent Whitson 104797895
/*
sockfd = socket(AF_INET, SOCK_STREAM, 0);   			//	#1
	if (sockfd<0) { //#2
	if (bind(sockfd,(struct sockaddr *) &servaddr,sizeof(servaddr))<0) { //#3
	if (listen(sockfd,5)<0) { //#4
	connfd = accept(sockfd,(struct sockaddr *) &cli,&len);          //#5
	n = read(sockfd,buff,MAX);//#6

	*/
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h>	
#include<unistd.h>

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 

	// infinite loop for chat 
	for (;;) { 
		bzero(buff, MAX); //erase contents of buff by writing zeros to it.

		// read the message from client and copy it in buffer 
		n = read(sockfd,buff,MAX);//#6 

		// print buffer which contains the client contents 
		printf("From client: %s\t To client : ", buff); 

		bzero(buff, MAX); 
		n = 0; 
		// copy server message in the buffer 
		while ((buff[n++] = getchar()) != '\n') 
			; 

		// and send that buffer to client 
		n = write(sockfd, buff, MAX);// #7

		// if msg contains "Exit" then server exit and chat ended. 
		if (strncmp("exit", buff, 4) == 0) { 
			printf("Server Exit...\n"); 
			break; 
		} 
	} 
} 

// Driver function 
int main() 
{ 
	int sockfd, connfd, len; 
	struct sockaddr_in servaddr, cli; 

	// socket create and return value checking 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);   			//	#1
	if (sockfd<0) { //#2
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 

	// Binding newly created socket to given IP and return value checking
	if (bind(sockfd,(struct sockaddr *) &servaddr,sizeof(servaddr))<0) { //#3
		printf("socket bind failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully binded..\n"); 

	// Now server is ready to listen and verification (return value check)
	//assume queue size is 5 
	if (listen(sockfd,5)<0) { //#4
		printf("Listen failed...\n"); 
		exit(0); 
	} 
	else
		printf("Server listening..\n"); 
	len = sizeof(cli); 

	// Accept the data packet from client and verification 
	connfd = accept(sockfd,(struct sockaddr *) &cli,&len);          //#5 
	if (connfd < 0) { 
		printf("server acccept failed...\n"); 
		exit(0); 
	} 
	else
		printf("server acccept the client...\n"); 

	// Function for chatting between client and server 
	func(connfd); 

	// After chatting close the socket 
	close(sockfd); 
} 

