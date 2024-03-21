// 5) write a TCP server client program to check if a given string is palindrome or not

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
#define PORT 8000
#define SA struct sockaddr

int isPalindrome(char str[], int size) {
    int n = size/2;
    for (int i = 0, j = size-1; i < n; i++, j--) {
        if (str[i] != str[j]) {
            return 0;
        }
    }
    return 1;
}

void func(int connfd) {
    char buff[MAX];

    while(1) {
        bzero(buff, MAX);

        read(connfd, buff, sizeof(buff));

        printf("string from client = %s\n", buff);
        printf("result sent to cient\n");
        int size = strlen(buff);
        int palindrome = isPalindrome(buff, size-1);
        bzero(buff, MAX);

        if (palindrome) {
            strcpy(buff, "The string is palindrome\n");
        }
        else {
            strcpy(buff, "The string is not a palindrome\n");
        }
        write(connfd, buff, sizeof(buff));
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