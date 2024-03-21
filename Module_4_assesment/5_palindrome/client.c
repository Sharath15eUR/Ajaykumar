// 5) write a TCP server client program to check if a given string is palindrome or not

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<strings.h>
#include<sys/socket.h>
#include<unistd.h>

#define MAX 80
#define PORT 8000
#define SA struct sockaddr

void func(int sockfd) {
    char buff[MAX];
    int n;

    while(1) {
        bzero(buff, sizeof(buff));

        printf("Enter the string : ");
        n = 0;

        while ((buff[n++] = getchar()) != '\n');

        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From the server : %s", buff);

        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client exit\n");
            break;
        }
    }
}

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1) {
        printf("Socket creation failed\n\n");
        exit(0);
    }
    else {
        printf("Scoket creation successful\n\n");
    }

    bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) {
        printf("Connection with server failed\n\n");
        exit(0);
    }
    else {
        printf("Connected to server\n\n");
    }

    func(sockfd);
    close(sockfd);
    return 0;
}