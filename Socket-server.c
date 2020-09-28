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
    exit(1);
}

int main(int argc, char *argv[]) {

     int socketfd, newsocketfd, portnumber, clilen,file;
     char buffer[1024], filename[50];
     struct socketaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR 404, Please provide a valid Port Number\n");
         exit(1);
     }

    // Creating the socket

     socketfd = socket(AF_INET, SOCK_STREAM, 0);
     if (socketfd < 0)
        error("ERROR Opening Socket");

     bzero((char *) &serv_addr, sizeof(serv_addr));
     portnumber = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portnumber);

     if (bind(socketfd, (struct socketaddr *) &serv_addr,
              sizeof(serv_addr)) < 0)
              error("ERROR binding");

     // incoming connection requests

     listen(socketfd,5);
     clilen = sizeof(cli_addr);

     // Accepting a new request, and creating a newsocketfd

     newsocketfd = accept(socketfd, (struct socketaddr *) &cli_addr, &clilen);
     if (newsocketfd < 0)
          error("ERROR Accepting");

     recv(newsocketfd,filename,sizeof(filename),0);

     printf("Request for File %s\n", filename);
     file=open(filename,O_RDONLY); // Opening the file in read-only mode

     if(file<0)
        send(newsocketfd,"file not found\n",20,0);
     else
        while((n=read(file,buffer,sizeof(buffer)))>0)

     // Reading the input sent by the client

     send(newsocketfd,buffer,n,0);
     printf("Request Sent!\n");
     close(file);

     n = write(newsocketfd,"Message has been Recieved!",18);
     if (n < 0) error("ERROR writing socket");
     return 0;
}
