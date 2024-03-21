// 6) write an example to demonstrate UDP server-client program

#include <stdio.h> 
#include <strings.h> 
#include <sys/types.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 
#include<netinet/in.h> 
#include<unistd.h> 
#include<stdlib.h> 

#define PORT 8000 
#define MAXLINE 1000 

int main() 
{
    int size = 50;
	char buffer[100]; 
    printf("Enter message to server : ");
	char message[size]; 
    fgets(message, sizeof(message), stdin);

	int sockfd, n; 
	struct sockaddr_in servaddr; 
	
	bzero(&servaddr, sizeof(servaddr)); 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 
	servaddr.sin_family = AF_INET; 
	
	sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
	
	if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) 
	{ 
		printf("\n Error : Connect Failed \n"); 
		exit(0); 
	} 
	sendto(sockfd, message, MAXLINE, 0, (struct sockaddr*)NULL, sizeof(servaddr)); 
	recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL); 
    printf("Reply from server = %s", buffer);
	close(sockfd); 
} 
