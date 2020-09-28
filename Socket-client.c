#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <fcntl.h>

void error(char *message) {

    perror(message);
    exit(0);
}

int main(int argc, char *argv[]) {

    int socketfd, portnumber, n;

    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 4) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    char filename[50];
    strcpy(filename,argv[3]);

    portnumber = atoi(argv[2]);
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portnumber);

    // Connecting to the Server

    if (connect(socketfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    send(socketfd,filename,sizeof(filename),0);

    n = write(socketfd,buffer,strlen(buffer));
    if (n < 0)
    error("ERROR writing to socket");
    bzero(buffer,256);

    n = read(socketfd,buffer,255);
    if (n < 0)
         error("ERROR reading from socket");
    printf("%s\n",buffer);

    return 0;
}
