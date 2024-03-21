// 4) Write a client/server model socket program to exchange hello messages between them 

#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<netinet/in.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<strings.h>

#define MAX 80
#define PORT 8080
#define SA struct sockaddr

void func(int connfd) {
    char buff[MAX];
    int n;

    while(1) {
        bzero(buff, MAX);

        read(connfd, buff, sizeof(buff));

        printf("message from client = %s\nsend message from server to cient : ",buff);
        bzero(buff, MAX);
        n = 0;

        while ((buff[n++] = getchar()) != '\n');

        write(connfd, buff, sizeof(buff));

        if (strncmp("exit", buff, 4) == 0) {
            printf("Server exit\n\n");
            break;
        }
    }
}

int main() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Socket creation failed\n\n");
        exit(0);
    }
    else {
        printf("Socket creation successful\n\n");
    }
    bzero(&servaddr, sizeof(servaddr));

    // assign ip and port
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Socket bind failed\n\n");
        exit(0);
    }
    else {
        printf("Socket bind successful\n\n");
    }

    if (listen(sockfd, 5) != 0) {
        printf("Listen failed\n\n");
        exit(0);
    }
    else {
        printf("Server is listening...\n\n");
    }

    len = sizeof(cli);
    connfd = accept(sockfd, (SA*)&cli, &len);

    if (connfd < 0) {
        printf("Server accept failed\n\n");
        exit(0);
    }
    else {
        printf("Server accept the client\n\n");
    }

    func(connfd);
    close(sockfd);
    return 0;
}