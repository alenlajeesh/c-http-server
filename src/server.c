#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include "../include/server.h"

#define BUFFER_SIZE 4096

void start_server(int port){
	int server_fd;
	int client_fd;

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	socklen_t client_len= sizeof(client_addr);
	
	char buffer[BUFFER_SIZE];

	server_fd =socket(AF_INET,SOCK_STREAM,0);
	if(server_fd<0){
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	server_addr.sin_family= AF_INET;
	server_addr.sin_addr.s_addr =INADDR_ANY;
	server_addr.sin_port=htons(port);

	if(bind(server_fd,(struct sockaddr *)&server_addr,sizeof(server_addr))<0){
		perror("bind failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	if(listen(server_fd,10)<0){
		perror("listen failed");
		close(server_fd);
		exit(EXIT_FAILURE);
	}

	printf("Server listening on port %d\n",port);

	while(1){
		client_fd=accept(server_fd,(struct sockaddr *)&client_addr,&client_len);

		if(client_fd<0){
			perror("accept failed");
			continue;
		}
		printf("Client connected\n");
		memset(buffer,0,BUFFER_SIZE);

		int bytes =read(client_fd,buffer,BUFFER_SIZE-1);

		if(bytes>0){
			printf("---HTTP Request----\n");
			printf("%s\n",buffer);
			printf("-------------------\n");
		}

		close(client_fd);
	}
}
