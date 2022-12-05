//Kent Whitson 104797895
/*
n = write(sockfd, buff, MAX);//  #8
n = read(sockfd, buff, MAX);// #9
sockfd = socket(AF_INET, SOCK_STREAM, 0);   //  #10
if (connect(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr))<0) { //#11
*/
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include<unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

void func(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		printf("Enter the string : "); 
		n = 0; 
		while ((buff[n++] = getchar()) != '\n') 
			; 
		//write the msge in buff to socket 
		n = write(sockfd, buff, MAX);//  #8
 
		bzero(buff, sizeof(buff)); 
		
		//read the mg to buff from socket,
		n = read(sockfd, buff, MAX);// #9

		printf("From Server : %s", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Client Exit...\n"); 
			break; 
		} 
	} 
} 

int main() 
{ 
	int sockfd, connfd; 
	struct sockaddr_in servaddr, cli; 

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0);   //  #10
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("137.207.82.53"); //connect to the same machine where server is running
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket , and return value checking
	if (connect(sockfd,(struct sockaddr*) &servaddr,sizeof(servaddr))<0) { //#11
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 

	// function for chat 
	func(sockfd); 

	// close the socket 
	close(sockfd); 
} 

