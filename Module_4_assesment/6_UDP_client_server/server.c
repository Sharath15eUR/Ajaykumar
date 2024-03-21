// 6) write an example to demonstrate UDP server-client program

#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#define PORT 8000 
#define MAXLINE 1000 

int main() 
{ 
    int size = 50;
    printf("server listening..\n");
	char buffer[100];
	char message[size];
	int listenfd, len; 
	struct sockaddr_in servaddr, cliaddr; 
	bzero(&servaddr, sizeof(servaddr)); 

	listenfd = socket(AF_INET, SOCK_DGRAM, 0);		 
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 

	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)); 
	 
	len = sizeof(cliaddr); 
	int n = recvfrom(listenfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&cliaddr,&len); 
	buffer[n] = '\0'; 

    printf("Message from client = %s\n", buffer);
    printf("Enter message to client : ");
    fgets(message, sizeof(message), stdin);
	sendto(listenfd, message, MAXLINE, 0, (struct sockaddr*)&cliaddr, sizeof(cliaddr)); 
    return 0;
} 
