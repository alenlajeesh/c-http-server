#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

#include "../include/server.h"
#include "../include/request.h"
#include "../include/response.h"

#define BUFFER_SIZE 4096

void* handle_client(void* arg)
{
    int client_fd = *(int*)arg;
    free(arg);

    char buffer[BUFFER_SIZE];
    HttpRequest request;

    memset(buffer, 0, BUFFER_SIZE);

    int bytes = read(client_fd, buffer, BUFFER_SIZE - 1);

    if (bytes > 0)
    {
        parse_http_request(buffer, &request);
        send_file_response(client_fd, request.path);
    }

    close(client_fd);
    return NULL;
}

void start_server(int port){
	int server_fd;
	
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	socklen_t client_len= sizeof(client_addr);
	
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
		int *client_fd = malloc(sizeof(int));

		if (!client_fd) {
			perror("malloc failed");
			 free(client_fd);
			continue;
		}

		*client_fd=accept(server_fd,(struct sockaddr *)&client_addr,&client_len);

		if(*client_fd<0){
			perror("accept failed");
			 free(client_fd);
			continue;
		}
		pthread_t thread;

		if (pthread_create(&thread, NULL, handle_client, client_fd) != 0){
			perror("pthread_create failed");
			close(*client_fd);
			free(client_fd);
			continue;
		}

		pthread_detach(thread);
	}
}
