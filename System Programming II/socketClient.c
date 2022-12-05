
#include <sys/types.h>
#include <sys/socket.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <arpa/inet.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <netdb.h>

#define SERVER_PORT 80
 
#define MAXLINE 4096
#define SA struct sockaddr
void err_n_die(const char* fmt, ...);

int main(int argc, char** argv)
{
	int sockfd, n;
	int sendbytes;
	struct sockaddr_in servaddr;
	char sendline[MAXLINE];
	char recvline[MAXLINE];

	//if (argc != 2) err_n_die("usage: %s <server adress>", argv[0]);
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);// err_n_die("error while creating socket");

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERVER_PORT);

	inet_pton(AF_INET, argv[1], &servaddr.sin_addr); //err_n_die("inet_pton error for %s",argv[1]);

	connect(sockfd, (SA*)& servaddr, sizeof(servaddr));// err_n_die("connection failed");

	sprintf(sendline, "GET / HTTP/1.1\r\n\r\n");
	sendbytes = strlen(sendline);

	write(sockfd, sendline, sendbytes);

	memset(recvline, 0, MAXLINE);
	
	while ((n = read(sockfd, recvline, MAXLINE - 1)) > 0)
	{
		printf("%s", recvline);
	}

	//if (n < 0) //err_n_die("read error");

	exit(0);
}