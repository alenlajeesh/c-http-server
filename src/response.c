#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#include "../include/response.h"

#define BUFFER_SIZE 4096

void send_file_response(int client_fd, const char *path){
	char full_path[512];
	snprintf(full_path,sizeof(full_path),"public%s",path);

	int file_fd= open(full_path,O_RDONLY);

	if(file_fd<0){
		send_404(client_fd);
		return;
	}

	char header[]=
		"HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "\r\n";
	write(client_fd,header,strlen(header));

	char buffer[BUFFER_SIZE];
	int bytes;

	while((bytes=read(file_fd,buffer,BUFFER_SIZE))>0){
		write(client_fd,buffer,bytes);
	}
	close(file_fd);
}

void send_404(int client_fd){
	char response[] =
        "HTTP/1.1 404 Not Found\r\n"
        "Content-Type: text/html\r\n"
        "\r\n"
        "<h1>404 Not Found</h1>";
	write(client_fd,response,strlen(response));
}
